/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calculate_sprite.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 12:37:11 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:13:17 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculate_sort_dist(t_map *b)
{
	int			i;
	int			j;
	int			tmp;
	double		tmp1;

	j = 0;
	i = -1;
	while (++i < b->numsprite)
	{
		j = i - 1;
		while (++j < b->numsprite)
		{
			if (b->spdist[i] < b->spdist[j])
			{
				tmp = b->spriteorder[i];
				b->spriteorder[i] = b->spriteorder[j];
				b->spriteorder[j] = tmp;
				tmp1 = b->spdist[i];
				b->spdist[i] = b->spdist[j];
				b->spdist[j] = tmp1;
				i = -1;
				j = b->numsprite;
			}
		}
	}
}

void	ft_calculate_sprite_dist(t_map *b)
{
	int		i;

	i = 0;
	while (i < b->numsprite)
	{
		b->spriteorder[i] = i;
		b->spdist[i] = ((b->posx - b->sprite[i].x) * (b->posx - b->sprite[i].x)
		+ (b->posy - b->sprite[i].y) * (b->posy - b->sprite[i].y));
		i++;
	}
	ft_calculate_sort_dist(b);
}

int		ft_norme(char *m, t_map *b)
{
	char	*str;

	if (!(str = ft_delete_space(m)))
		return (0);
	if (!(check_character(str, b)))
		return (0);
	if (!(b->area = ft_split(str, '\n')))
		return (0);
	free(str);
	return (1);
}
