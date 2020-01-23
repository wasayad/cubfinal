/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 17:33:12 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:25:02 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sky_ground(t_map *b)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++j < b->res->y / 2)
	{
		i = -1;
		while (++i < b->res->x)
		{
			b->imgdata[j * b->res->x + i] = b->color_s;
		}
	}
	while (j < b->res->y)
	{
		i = -1;
		while (++i < b->res->x)
		{
			b->imgdata[j * b->res->x + i] = b->color_g;
		}
		j++;
	}
}

void	ft_draw(t_map *b)
{
	if (b->side == 0)
		b->texy = b->stepy > 0 ? ((int)b->texpos & b->noheight - 1) :
		((int)b->texpos & b->suheight - 1);
	else if (b->side == 1)
		b->texy = b->stepx < 0 ? ((int)b->texpos & b->eaheight - 1) :
		((int)b->texpos & b->weheight - 1);
	if (b->side == 0)
		b->colori = b->stepy > 0 ? b->imgnod[b->noheight * b->texy +
		b->texx] : b->imgsud[b->suheight * b->texy + b->texx];
	else if (b->side == 1)
		b->colori = b->stepx < 0 ? b->imgead[b->eaheight * b->texy +
		b->texx] : b->imgwed[b->weheight * b->texy + b->texx];
	b->texpos += b->step;
}

void	calculate_ray(t_map *b, int i)
{
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	b->camerax = 2 * i / (double)b->res->x - 1;
	b->raydirx = b->dirx + b->planex * b->camerax;
	b->raydiry = b->diry + b->planey * b->camerax;
	step_compt(b);
	ft_hit(b);
	ft_lineheight(b);
	ft_calculate_texture(b);
	while (b->drawstart <= b->drawend)
	{
		ft_draw(b);
		b->imgdata[b->drawstart++ * b->res->x + i] = b->colori;
	}
}

int		compt_case(t_map *b)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	draw_sky_ground(b);
	while (i < b->res->x)
	{
		calculate_ray(b, i);
		b->zbuffer[i] = b->perpwalldist;
		i++;
	}
	i = 0;
	while (i < b->numsprite)
	{
		ft_calculate_sprite(b, i);
		ft_draw_sprite(b);
		i++;
	}
	if (b->screenshot == 1)
		ft_save_bitmap("bitmap.bmp", b);
	mlx_put_image_to_window(b->data->mlx_ptr,
	b->data->mlx_win, b->imgptr, 0, 0);
	return (1);
}

void	ft_draw_sprite(t_map *b)
{
	int		i;

	while (b->drawstartx < b->drawendx && b->drawstartx < b->res->x)
	{
		i = b->drawstarty;
		b->texx = (int)(256 * (b->drawstartx -
		(-b->spw / 2 + b->spscreenx)) * b->spwidth / b->spw) / 256;
		control_draw(b);
		if (b->drawstartx < b->res->x && b->transy > 0 &&
		b->drawstartx > 0 && b->transy < b->zbuffer[b->drawstartx])
		{
			while (++i < b->drawendy && i < b->res->y)
			{
				b->d = i * 256 - b->res->y * 128 + b->sph * 128;
				b->texy = (int)((b->d * b->spheight) / b->sph) / 256;
				control_draw(b);
				if (b->spwidth * b->texy + b->texx < b->spwidth * b->spheight)
					b->colori = b->imgspd[b->spwidth * b->texy + b->texx];
				if ((b->colori & 0xffffff) != 0 && b->res->x
				* b->res->y > i * b->res->x + b->drawstartx)
					b->imgdata[i * b->res->x + b->drawstartx] = b->colori;
			}
		}
		b->drawstartx++;
	}
}
