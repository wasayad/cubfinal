/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_map.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 11:38:07 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 21:41:38 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	condition(t_map *b, int i, int j)
{
	if (b->area[j] && ft_strchr("NSEW", b->area[j][i]))
	{
		if (b->area[j][i] == 'N')
		{
			b->dirx = 0;
			b->diry = -1;
		}
		if (b->area[j][i] == 'S')
		{
			b->dirx = 0;
			b->diry = 1;
		}
		if (b->area[j][i] == 'E')
		{
			b->dirx = 1;
			b->diry = 0;
		}
		if (b->area[j][i] == 'W')
		{
			b->dirx = -1;
			b->diry = 0;
		}
		b->posx = (double)i + 0.5;
		b->posy = (double)j + 0.5;
	}
}

char		*check_character(char *m, t_map *b)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (m[++i])
	{
		if ((m[i] != ' ' && (m[i] != '\n' || (i > 0 && (m[i] == '\n' &&
		m[i + 1] == '\n' && m[i - 1] == '1'))) &&
		(ft_strchr("NSEW", m[i])) == NULL
		&& (m[i] > '2' || m[i] < '0')) ||
		(ft_strchr("NSEW", m[i]) && j == 1))
		{
			ft_printf(2, "Error\n-> map file may have to much ");
			ft_printf(2, "index or a syntax error on map description\n");
			ft_exit(b);
		}
		if (ft_strchr("NSEW", m[i]))
			j++;
	}
	if (j == 0)
		return (NULL);
	return ("ok");
}

static char	*check_invalid(t_map *b, int i, int j, int check_y)
{
	condition(b, i, j);
	if (b->area[j] && ft_strchr("NSEW", b->area[j][i]))
		b->area[j][i] = '0';
	if (b->area[j] && (check_y - 1 == j || j == 0 || i == 0
	|| b->area[j][i + 1] == '\0') &&
	(b->area[j][i] != '1' && b->area[j][i] != ' '))
	{
		ft_printf(2, "Error\n-> map || map must be surrounded by character ");
		ft_printf(2, "'1' || map character are '0' '1' '2' || only a ");
		ft_printf(2, "single 'N/S/W/E' character || no two consectuve 'NL'\n");
		ft_exit(b);
	}
	return ("ok");
}

int			ft_check_area(char *m, t_map *b)
{
	int i;
	int j;
	int check_y;

	check_y = 0;
	j = 0;
	i = -1;
	if (!(ft_norme(m, b)))
		return (0);
	while (b->area[check_y])
		check_y++;
	while (b->area[j])
	{
		if (b->area[j][++i] == '\0')
		{
			j++;
			i = 0;
		}
		if (b->area[j] != NULL && b->area[j][i] == '2')
			ft_realloc_struct(b, j, i);
		check_invalid(b, i, j, check_y);
	}
	return (1);
}

int			ft_check_map(t_map *b)
{
	ft_check_map_01(b);
	if (ft_strnstr(b->map, "C"))
	{
		if (!(ft_get_color_sky(ft_strnstr(b->map, "C") + 1, b)))
		{
			ft_printf(2, "Error\n-> color sky || index : C\n");
			ft_exit(b);
		}
		ft_del_line(b, "C");
	}
	else
	{
		ft_printf(2, "Error\n-> Missing 'C' index\n");
		ft_exit(b);
	}
	if (!(ft_check_area(b->map, b)))
	{
		ft_printf(2, "Error\n-> map || map must be surrounded by character ");
		ft_printf(2, "'1' || map character are '0' '1' '2' || only a ");
		ft_printf(2, "single 'N/S/W/E' character\n");
		ft_exit(b);
	}
	ft_init_struct_01(b);
	ft_check_line(b);
	return (1);
}
