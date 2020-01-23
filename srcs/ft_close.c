/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:03:32 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:49:39 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_exit(void *param)
{
	t_map *b;

	b = param;
	if (b->where > 0)
		mlx_destroy_window(b->data->mlx_ptr, b->data->mlx_win);
	if (b->where > 1)
	{
		mlx_destroy_image(b->data->mlx_ptr, b->imgptr);
		if (b->where > 1 && b->imgno != 0)
			mlx_destroy_image(b->data->mlx_ptr, b->imgno);
		if (b->where > 2 && b->imgsu != 0)
			mlx_destroy_image(b->data->mlx_ptr, b->imgsu);
		if (b->where > 3 && b->imgea != 0)
			mlx_destroy_image(b->data->mlx_ptr, b->imgea);
		if (b->where > 4 && b->imgwe != 0)
			mlx_destroy_image(b->data->mlx_ptr, b->imgwe);
		if (b->where > 5 && b->imgsp != 0)
			mlx_destroy_image(b->data->mlx_ptr, b->imgsp);
	}
	ft_exit_01(b);
}

void			ft_exit_01(t_map *b)
{
	ft_free((void *)&(b->map));
	ft_free((void *)&(b->spriteorder));
	ft_free((void *)&(b->spdist));
	ft_free((void *)&(b->path->ea));
	ft_free((void *)&(b->path->no));
	ft_free((void *)&(b->path->so));
	ft_free((void *)&(b->path->we));
	ft_free((void *)&(b->path->sp));
	ft_free((void *)&(b->res));
	ft_free((void *)&(b->data));
	ft_free((void *)&(b->path));
	ft_free((void *)&(b->sprite));
	ft_free((void *)&(b->zbuffer));
	ft_free((void *)&(b->color));
	ft_free_tab(b);
	ft_free((void *)&(b));
	exit(1);
}

void			ft_init_struct_nul(t_map *b)
{
	b->path->ea = NULL;
	b->path->no = NULL;
	b->path->we = NULL;
	b->path->so = NULL;
	b->path->sp = NULL;
	b->area = NULL;
	b->zbuffer = NULL;
	b->spdist = NULL;
	b->spriteorder = NULL;
	b->imgno = NULL;
	b->imgsu = NULL;
	b->imgea = NULL;
	b->imgwe = NULL;
	b->imgsp = NULL;
	b->imgptr = NULL;
}

void			ft_free_tab(t_map *b)
{
	int		i;

	i = 0;
	if (b->area != NULL)
	{
		while (b->area[i] != 0)
		{
			free(b->area[i]);
			i++;
		}
		free(b->area[i]);
		free(b->area);
	}
	b->area = NULL;
}

void			ft_free(void **f)
{
	free(*f);
	*f = NULL;
}
