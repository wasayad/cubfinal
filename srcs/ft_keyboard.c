/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keyboard.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 18:06:43 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 21:10:57 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		move_front(t_map *b)
{
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	if (b->area[(int)(b->posy + b->diry * b->movespeed)]
	[(int)(b->posx + b->dirx * b->movespeed)] == '1' ||
	ft_hint_object(b, b->posx + b->dirx * b->movespeed,
	b->posy + b->diry * b->movespeed))
		return (1);
	b->posy += b->diry * b->movespeed;
	b->posx += b->dirx * b->movespeed;
	compt_case(b);
	return (1);
}

int		move_back(t_map *b)
{
	b->mapx = (int)b->posx;
	b->mapy = (int)b->posy;
	if (b->area[(int)(b->posy - b->diry * b->movespeed)]
	[(int)(b->posx - b->dirx * b->movespeed)] == '1' ||
	ft_hint_object(b, b->posx - (b->dirx * b->movespeed),
	b->posy - (b->diry * b->movespeed)))
		return (1);
	b->posy -= b->diry * b->movespeed;
	b->posx -= b->dirx * b->movespeed;
	compt_case(b);
	return (1);
}

int		rotate_left(t_map *b)
{
	b->oldirx = b->dirx;
	b->dirx = b->dirx * cos(-b->rotspeed) - b->diry * sin(-b->rotspeed);
	b->diry = b->oldirx * sin(-b->rotspeed) + b->diry * cos(-b->rotspeed);
	b->oldplanex = b->planex;
	b->planex = b->planex * cos(-b->rotspeed)
	- b->planey * sin(-b->rotspeed);
	b->planey = b->oldplanex * sin(-b->rotspeed)
	+ b->planey * cos(-b->rotspeed);
	compt_case(b);
	return (1);
}

int		rotate_right(t_map *b)
{
	b->oldirx = b->dirx;
	b->dirx = b->dirx * cos(b->rotspeed) - b->diry * sin(b->rotspeed);
	b->diry = b->oldirx * sin(b->rotspeed) + b->diry * cos(b->rotspeed);
	b->oldplanex = b->planex;
	b->planex = b->planex * cos(b->rotspeed)
	- b->planey * sin(b->rotspeed);
	b->planey = b->oldplanex * sin(b->rotspeed)
	+ b->planey * cos(b->rotspeed);
	compt_case(b);
	return (1);
}

int		gere_key(int keycode, void *param)
{
	t_map *b;

	b = param;
	if (keycode == 13)
		move_front(b);
	if (keycode == 1)
		move_back(b);
	if (keycode == 0)
		move_side_left(b);
	if (keycode == 2)
		move_side_right(b);
	if (keycode == 123)
		rotate_left(b);
	if (keycode == 124)
		rotate_right(b);
	if (keycode == 53)
		ft_exit(b);
	return (1);
}
