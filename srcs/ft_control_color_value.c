/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_control_color_value.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 16:01:59 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:33:06 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_index(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || (str[i] <= '9' && str[i] >= '0')))
		i++;
	return (i);
}

void	ft_control_res(t_map *b)
{
	if (b->res->x > 2560)
	{
		ft_printf(2, "Warning\n-> map width is %d but maximum ", b->res->x);
		ft_printf(2, "screen width is 2560 || Map width resized\n");
		b->res->x = 2560;
	}
	if (b->res->y > 1520)
	{
		ft_printf(2, "Warning\n-> map height is %d but maximum ", b->res->y);
		ft_printf(2, "screen height is 1520 || Map height resized\n");
		b->res->y = 1520;
	}
	if (b->res->x < 150)
	{
		ft_printf(2, "Warning\n-> too small map width is forbidden ");
		ft_printf(2, "|| Map width resized to 150\n");
		b->res->x = 150;
	}
	if (b->res->y < 150)
	{
		ft_printf(2, "Warning\n-> too small map height is forbidden ");
		ft_printf(2, "|| Map height resized to 150\n");
		b->res->y = 150;
	}
}

int		ft_atoi_color(const char *str)
{
	int			i;
	long		res;

	res = 0;
	i = 1;
	while (((*str >= 9 && *str <= 13) && *str != 10) || *str == ' ')
		str++;
	if (*str == '-')
	{
		i = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	return (res * i);
}
