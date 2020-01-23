/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_control_map_01.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 14:45:49 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:42:34 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_map_06(t_map *b)
{
	if (ft_strnstr(b->map, "NO"))
	{
		if (!(ft_get_path_no(ft_strnstr(b->map, "NO") + 2, b)))
		{
			ft_printf(2, "Error\n-> texture path north || index : NO\n");
			ft_exit(b);
		}
		ft_del_line(b, "NO");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'NO' index\n");
		ft_exit(b);
	}
	ft_check_map_07(b);
}

void	ft_check_map_07(t_map *b)
{
	if (ft_strnstr(b->map, "F "))
	{
		if (!(ft_get_color_ground(ft_strnstr(b->map, "F ") + 1, b)))
		{
			ft_printf(2, "Error\n-> color ground || index : F\n");
			ft_exit(b);
		}
		ft_del_line(b, "F ");
	}
	else
	{
		ft_printf(2, "Error\n-> : Missing 'F' index\n");
		ft_exit(b);
	}
}

void	ft_control_map_name(char **ag, t_map *b)
{
	int		i;

	i = 0;
	while (ag[1][i] && ag[1][i] != '.')
		i++;
	b->screenshot = 0;
	b->where = 0;
	if (ft_strncmp(ag[1] + i, ".cub", ft_strlen(".cub")) != 0)
	{
		ft_printf(2, "Error\n-> wrong map file || must end by .cub\n");
		ft_exit(b);
	}
}

void	ft_check_line(t_map *b)
{
	int		i;

	i = 0;
	while (b->area[i])
	{
		if (ft_strlen(b->area[i]) != ft_strlen(b->area[0]))
		{
			ft_printf(2, "Error\n-> line lenght\n");
			ft_exit(b);
		}
		i++;
	}
}

int		ft_hint_object(t_map *b, double addx, double addy)
{
	if (b->area[b->mapy][b->mapx] == '2')
	{
		if (((addx) - b->mapx < 0.7 && (addx) - b->mapx > 0.3) &&
		((addy) - b->mapy < 0.7 && (addy) - b->mapy > 0.3))
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}
