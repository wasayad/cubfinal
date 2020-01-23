/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_control_value.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 17:07:08 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:42:07 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_control_value_color_s(t_map *b, int i)
{
	if (i < 0 || i > 255)
	{
		ft_printf(2, "Error\n-> value color || index C\n");
		ft_exit(b);
	}
	return (i);
}

int		ft_control_value_color_g(t_map *b, int i)
{
	if (i < 0 || i > 255)
	{
		ft_printf(2, "Error\n-> value color || index F\n");
		ft_exit(b);
	}
	return (i);
}

void	ft_check_map_01(t_map *b)
{
	if (ft_strnstr(b->map, "R"))
	{
		if (!(ft_get_resolution(ft_strnstr(b->map, "R") + 1, b)))
		{
			ft_printf(2, "Error\n-> map resolution || index : R\n");
			ft_exit(b);
		}
		ft_del_line(b, "R");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'R' index\n");
		ft_exit(b);
	}
	ft_check_map_02(b);
}

void	ft_check_map_02(t_map *b)
{
	if (ft_strnstr(b->map, "EA"))
	{
		if (!(ft_get_path_ea(ft_strnstr(b->map, "EA") + 2, b)))
		{
			ft_printf(2, "Error\n-> texture path east || index : EA\n");
			ft_exit(b);
		}
		ft_del_line(b, "EA");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'EA' index\n");
		ft_exit(b);
	}
	ft_check_map_03(b);
}
