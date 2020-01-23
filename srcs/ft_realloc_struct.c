/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc_struct.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 21:24:30 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:30:14 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite		*ft_create_substruct(t_map *b, double x, double y)
{
	int			i;
	t_sprite	*sprit;

	i = 0;
	while (b->sprite[i].x != -1)
		i++;
	if (!(sprit = malloc(sizeof(t_sprite) * (i + 2))))
		ft_exit(b);
	i = -1;
	while (b->sprite[++i].x != -1)
	{
		sprit[i].x = b->sprite[i].x;
		sprit[i].y = b->sprite[i].y;
	}
	sprit[i].x = x + 0.5;
	sprit[i].y = y + 0.5;
	sprit[i + 1].x = -1;
	free(b->sprite);
	if (!(b->sprite = malloc(sizeof(t_sprite) * (i + 2))))
		ft_exit(b);
	return (sprit);
}

int				ft_realloc_struct(t_map *b, double y, double x)
{
	int			i;
	t_sprite	*sprit;

	if (!(sprit = ft_create_substruct(b, x, y)))
		ft_exit(b);
	i = -1;
	while (sprit[++i].x != -1)
	{
		b->sprite[i].x = sprit[i].x;
		b->sprite[i].y = sprit[i].y;
	}
	b->sprite[i].x = -1;
	free(sprit);
	b->numsprite++;
	return (1);
}

int				move_side_left(t_map *b)
{
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	if (b->area[(int)(b->posy - b->planey * b->movespeed)]
	[(int)(b->posx - b->planex * b->movespeed)] == '1' ||
	ft_hint_object(b, b->posy - b->planey * b->movespeed,
	b->posx - b->planex * b->movespeed))
		return (1);
	b->posy -= b->planey * b->movespeed;
	b->posx -= b->planex * b->movespeed;
	compt_case(b);
	return (1);
}

int				move_side_right(t_map *b)
{
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	if (b->area[(int)(b->posy + b->planey * b->movespeed)]
	[(int)(b->posx + b->planex * b->movespeed)] == '1' ||
	ft_hint_object(b, b->posy + b->planey * b->movespeed,
	b->posx + b->planex * b->movespeed))
		return (1);
	b->posy += b->planey * b->movespeed;
	b->posx += b->planex * b->movespeed;
	compt_case(b);
	return (1);
}
