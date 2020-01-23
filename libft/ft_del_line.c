/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 16:56:14 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 15:50:59 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_len_n(t_map *b, char *c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (b->map[i] && b->map + i != ft_strnstr(b->map, c))
		i++;
	while (b->map[i] && b->map[i] != '\n')
	{
		i++;
		j++;
	}
	return (j);
}

char			*ft_del_line(t_map *b, char *c)
{
	int		i;
	char	*newstr;
	int		check;
	int		j;

	j = 0;
	check = 0;
	if (!(newstr = malloc(sizeof(char *) *
	((ft_strlen(b->map) - ft_len_n(b, "\n"))))))
		ft_exit(b);
	i = -1;
	while (b->map[++i])
	{
		if (b->map + i == ft_strnstr(b->map, c))
			check = 1;
		if (i > 0 && b->map[i - 1] == '\n' &&
		b->map + i != ft_strnstr(b->map, c))
			check = 0;
		if (check == 0)
			newstr[j++] = b->map[i];
	}
	newstr[j] = '\0';
	free(b->map);
	return ((b->map = ft_strjoinf(newstr, "")));
}
