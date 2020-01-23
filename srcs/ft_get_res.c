/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_res.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 15:53:45 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:16:12 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_get_resolution(char *s, t_map *b)
{
	int		i;

	i = -1;
	if (s == NULL)
		return (0);
	while (s[++i] && s[i] != '\n')
		if (s[i] != ' ' && (s[i] > '9' || s[i] < '0'))
			return (0);
	i = 0;
	b->res->x = ft_atoi(s);
	while ((s[i] && (s[i] >= 9 && s[i] <= 13)) || s[i] == ' ')
		i++;
	while (s[i] && (s[i] <= '9' && s[i] >= '0'))
		i++;
	while ((s[i] && (s[i] >= 9 && s[i] <= 13)) || s[i] == ' ')
		i++;
	b->res->y = ft_atoi(s + i);
	while (s[i] && (s[i] <= '9' && s[i] >= '0'))
		i++;
	while (s[i] && ((s[i] != 10 && (s[i] >= 9 && s[i] <= 13)) || s[i] == ' '))
		i++;
	if (s[i] != '\n')
		return (0);
	ft_control_res(b);
	return (1);
}
