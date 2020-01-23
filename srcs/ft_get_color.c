/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_color.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 21:10:18 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 12:55:20 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		ft_get_color(char *str, int i)
{
	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] && str[i] != '\n')
		if ((str[i] != ' ' && str[i] != ',') && (str[i] > '9' || str[i] < '0'))
			return (0);
	return (1);
}

int				ft_get_color_ground(char *str, t_map *b)
{
	int		i;

	i = 0;
	if (!(ft_get_color(str, i)))
		return (0);
	b->color->rgb.r = ft_control_value_color_g(b, ft_atoi_color(str));
	i = ft_index(str, i);
	if (str[i] == ',')
		i++;
	b->color->rgb.g = ft_control_value_color_g(b, ft_atoi_color(str + i));
	i = ft_index(str, i);
	if (str[i] == ',')
		i++;
	b->color->rgb.b = ft_control_value_color_g(b, ft_atoi_color(str + i));
	i = ft_index(str, i);
	if (str[i] != '\n')
		return (0);
	b->color_g = b->color->color;
	return (1);
}

int				ft_get_color_sky(char *str, t_map *b)
{
	int		i;

	i = 0;
	if (!(ft_get_color(str, i)))
		return (0);
	b->color->rgb.r = ft_control_value_color_s(b, ft_atoi_color(str));
	while (str[i] && (str[i] == ' ' || (str[i] <= '9' && str[i] >= '0')))
		i++;
	if (str[i] == ',')
		i++;
	b->color->rgb.g = ft_control_value_color_s(b, ft_atoi_color(str + i));
	while (str[i] && (str[i] == ' ' || (str[i] <= '9' && str[i] >= '0')))
		i++;
	if (str[i] == ',')
		i++;
	b->color->rgb.b = ft_control_value_color_s(b, ft_atoi_color(str + i));
	while (str[i] && (str[i] == ' ' || (str[i] <= '9' && str[i] >= '0')))
		i++;
	if (str[i] != '\n')
		return (0);
	b->color_s = b->color->color;
	return (1);
}
