/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 17:12:12 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:50:03 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	step_compt(t_map *b)
{
	b->deltadistx = sqrt((double)1 +
	(b->raydiry * b->raydiry) / (b->raydirx * b->raydirx));
	b->deltadisty = sqrt((double)1 +
	(b->raydirx * b->raydirx) / (b->raydiry * b->raydiry));
	if (b->raydirx < 0)
	{
		b->stepx = -1;
		b->sidedistx = (b->posx - b->mapx) * b->deltadistx;
	}
	else
	{
		b->stepx = 1;
		b->sidedistx = (b->mapx + 1.0 - b->posx) * b->deltadistx;
	}
	if (b->raydiry < 0)
	{
		b->stepy = -1;
		b->sidedisty = (b->posy - b->mapy) * b->deltadisty;
	}
	else
	{
		b->stepy = 1;
		b->sidedisty = (b->mapy + 1.0 - b->posy) * b->deltadisty;
	}
}

void	ft_hit_inside(t_map *b)
{
	if (b->sidedistx < b->sidedisty)
	{
		b->sidedistx += b->deltadistx;
		b->mapx += b->stepx;
		b->side = 1;
	}
	else
	{
		b->sidedisty += b->deltadisty;
		b->mapy += b->stepy;
		b->side = 0;
	}
	if (b->area[b->mapy][b->mapx] == '1')
		b->hit = 1;
	if (b->area[b->mapy][b->mapx] == '2')
	{
		b->spy = b->mapy;
		b->spx = b->mapx;
	}
}

void	ft_hit(t_map *b)
{
	b->hit = 0;
	b->side = 0;
	while (b->hit == 0)
	{
		ft_hit_inside(b);
	}
	if (b->side == 1)
		b->perpwalldist = (b->mapx - b->posx + (1 - b->stepx) / 2) / b->raydirx;
	else
		b->perpwalldist = (b->mapy - b->posy + (1 - b->stepy) / 2) / b->raydiry;
}

void	ft_lineheight(t_map *b)
{
	b->lineheight = (int)(b->res->y / b->perpwalldist);
	b->drawstart = -b->lineheight / 2 + b->res->y / 2;
	if (b->drawstart < 0)
		b->drawstart = 0;
	b->drawend = b->lineheight / 2 + b->res->y / 2;
	if (b->drawend >= b->res->y)
		b->drawend = b->res->y - 1;
}

void	ft_calculate_sprite(t_map *b, int i)
{
	ft_calculate_sprite_dist(b);
	b->spritex = b->sprite[b->spriteorder[i]].x - b->posx;
	b->spritey = b->sprite[b->spriteorder[i]].y - b->posy;
	b->invdet = 1.0 / (b->planex * b->diry - b->dirx * b->planey);
	b->transx = b->invdet * (b->diry * b->spritex - b->dirx * b->spritey);
	b->transy = b->invdet * (-b->planey * b->spritex + b->planex * b->spritey);
	b->spscreenx = (int)((b->res->x / 2) * (1 + b->transx / b->transy));
	b->sph = abs((int)(b->res->y / b->transy));
	b->drawstarty = -b->sph / 2 + b->res->y / 2;
	if (b->drawstarty < 0)
		b->drawstarty = 0;
	b->drawendy = b->sph / 2 + b->res->y / 2;
	if (b->drawstarty >= b->res->y)
		b->drawstarty = b->res->y - 1;
	b->spw = abs((int)(b->res->y / (b->transy)));
	b->drawstartx = -b->spw / 2 + b->spscreenx;
	if (b->drawstartx < 0)
		b->drawstartx = 0;
	b->drawendx = b->spw / 2 + b->spscreenx;
	if (b->drawendx >= b->res->x)
		b->drawendx = b->res->x - 1;
}
