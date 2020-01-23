/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 12:30:56 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:53:33 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_fov(t_map *b)
{
	if (b->diry == -1.0 && b->dirx == 0.0)
	{
		b->planex = 0.60;
		b->planey = 0;
	}
	if (b->dirx == 0.0 && b->diry == 1.0)
	{
		b->planex = -0.6;
		b->planey = 0;
	}
	if (b->dirx == 1.0 && b->diry == 0.0)
	{
		b->planex = 0;
		b->planey = 0.6;
	}
	if (b->dirx == -1.0 && b->diry == 0.0)
	{
		b->planex = 0;
		b->planey = -0.6;
	}
}

void	init_ray(t_map *b)
{
	ft_init_fov(b);
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	b->movespeed = 0.075;
	b->rotspeed = 0.05;
	b->imgptr = mlx_new_image(b->data->mlx_ptr, b->res->x, b->res->y);
	b->imgdata = (int *)mlx_get_data_addr(b->imgptr,
	&b->bpp, &b->size_l, &b->endian);
	b->texture_check = 0;
	if (!(b->zbuffer = malloc(sizeof(double) * b->res->x)))
		ft_exit(b);
}

int		instance_texture(t_map *b)
{
	instance_texture_01(b);
	if (!(b->imgsp = mlx_xpm_file_to_image(b->data->mlx_ptr, b->path->sp,
	&b->spwidth, &b->spheight)))
	{
		ft_printf(2, "Error\n-> Failed loading texture : %s\n", b->path->sp);
		b->where = 6;
		ft_exit(b);
	}
	b->where = 6;
	b->imgspd = (int *)mlx_get_data_addr(b->imgsp,
	&b->bpp, &b->size_l, &b->endian);
	return (1);
}

int		ft_init_struct_01(t_map *b)
{
	if (!(b->spriteorder = malloc(sizeof(int) * (b->numsprite + 1))))
		ft_exit(b);
	if (!(b->spdist = malloc(sizeof(double) * (b->numsprite + 1))))
		ft_exit(b);
	return (1);
}

t_map	*init_struct(void)
{
	t_map *b;

	if (!(b = malloc(sizeof(t_map) * 1)))
		return (NULL);
	if (!(b->color = malloc(sizeof(t_rgb) * 1)))
		return (NULL);
	if (!(b->res = malloc(sizeof(t_res) * 1)))
		return (0);
	if (!(b->data = malloc(sizeof(t_data) * 1)))
		return (0);
	if (!(b->path = malloc(sizeof(t_path) * 1)))
		return (0);
	if (!(b->sprite = malloc(sizeof(t_sprite) * 1)))
		return (0);
	ft_init_struct_nul(b);
	b->sprite[0].x = -1;
	b->numsprite = 1;
	return (b);
}
