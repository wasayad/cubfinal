/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calculate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 17:33:47 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 19:36:48 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculate_texture_no(t_map *b)
{
	if (b->side == 1)
		b->wallx = b->posy + b->perpwalldist * b->raydiry;
	else
		b->wallx = b->posx + b->perpwalldist * b->raydirx;
	b->wallx -= floor((b->wallx));
	b->texx = (int)(b->wallx * (double)b->nowidth);
	if (b->side == 0 && b->raydiry > 0)
		b->texx = b->nowidth - b->texx - 1;
	if (b->side == 1 && b->raydirx < 0)
		b->texx = b->nowidth - b->texx - 1;
	b->step = 1.0 * b->noheight / b->lineheight;
	b->texpos = (b->drawstart - b->res->y / 2 + b->lineheight / 2) * b->step;
}

void	ft_calculate_texture_we(t_map *b)
{
	if (b->side == 1)
		b->wallx = b->posy + b->perpwalldist * b->raydiry;
	else
		b->wallx = b->posx + b->perpwalldist * b->raydirx;
	b->wallx -= floor((b->wallx));
	b->texx = (int)(b->wallx * (double)b->wewidth);
	if (b->side == 0 && b->raydiry > 0)
		b->texx = b->wewidth - b->texx - 1;
	if (b->side == 1 && b->raydirx > 0)
		b->texx = b->wewidth - b->texx - 1;
	b->step = 1.0 * b->weheight / b->lineheight;
	b->texpos = (b->drawstart - b->res->y / 2 + b->lineheight / 2) * b->step;
}

void	ft_calculate_texture_su(t_map *b)
{
	if (b->side == 1)
		b->wallx = b->posy + b->perpwalldist * b->raydiry;
	else
		b->wallx = b->posx + b->perpwalldist * b->raydirx;
	b->wallx -= floor((b->wallx));
	b->texx = (int)(b->wallx * (double)b->suwidth);
	if (b->side == 0 && b->raydiry > 0)
		b->texx = b->suwidth - b->texx - 1;
	if (b->side == 1 && b->raydirx < 0)
		b->texx = b->suwidth - b->texx - 1;
	b->step = 1.0 * b->suheight / b->lineheight;
	b->texpos = (b->drawstart - b->res->y / 2 + b->lineheight / 2) * b->step;
}

void	ft_calculate_texture_ea(t_map *b)
{
	if (b->side == 1)
		b->wallx = b->posy + b->perpwalldist * b->raydiry;
	else
		b->wallx = b->posx + b->perpwalldist * b->raydirx;
	b->wallx -= floor((b->wallx));
	b->texx = (int)(b->wallx * (double)b->eawidth);
	if (b->side == 0 && b->raydiry > 0)
		b->texx = b->eawidth - b->texx - 1;
	if (b->side == 1 && b->raydirx < 0)
		b->texx = b->eawidth - b->texx - 1;
	b->step = 1.0 * b->eaheight / b->lineheight;
	b->texpos = (b->drawstart - b->res->y / 2 + b->lineheight / 2) * b->step;
}

void	ft_calculate_texture(t_map *b)
{
	if (b->side == 1 && b->stepx < 0)
	{
		ft_calculate_texture_ea(b);
	}
	if (b->side == 1 && b->stepx >= 0)
	{
		ft_calculate_texture_we(b);
	}
	if (b->side == 0 && b->stepy <= 0)
	{
		ft_calculate_texture_su(b);
	}
	if (b->side == 0 && b->stepy > 0)
	{
		ft_calculate_texture_no(b);
	}
}
