/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map_control.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 14:20:13 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:42:23 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_map_03(t_map *b)
{
	if (ft_strnstr(b->map, "WE"))
	{
		if (!(ft_get_path_we(ft_strnstr(b->map, "WE") + 2, b)))
		{
			ft_printf(2, "Error\n-> texture path west || index : WE\n");
			ft_exit(b);
		}
		ft_del_line(b, "WE");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'WE' index\n");
		ft_exit(b);
	}
	ft_check_map_04(b);
}

void	ft_check_map_04(t_map *b)
{
	if (ft_strnstr(b->map, "SO"))
	{
		if (!(ft_get_path_so(ft_strnstr(b->map, "SO") + 2, b)))
		{
			ft_printf(2, "Error\n-> texture path south || index : SO\n");
			ft_exit(b);
		}
		ft_del_line(b, "SO");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'SO' index\n");
		ft_exit(b);
	}
	ft_check_map_05(b);
}

void	ft_check_map_05(t_map *b)
{
	if (ft_strnstr(b->map, "S"))
	{
		if (!(ft_get_path_sp(ft_strnstr(b->map, "S") + 1, b)))
		{
			ft_printf(2, "Error\n -> texture path sprite || index : SP\n");
			ft_exit(b);
		}
		ft_del_line(b, "S");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'S' index\n");
		ft_exit(b);
	}
	ft_check_map_06(b);
}

char	*ft_delete_space(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ')
			j++;
	if (!(tmp = malloc(sizeof(char *) * j + 1)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ')
			tmp[j++] = str[i];
	tmp[j] = '\0';
	return (tmp);
}
