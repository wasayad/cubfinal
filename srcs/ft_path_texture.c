/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_path_texture.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:40:34 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 18:43:59 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_get_path_ea(char *str, t_map *b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '/')
	{
		if (!((str[i] >= 9 && str[i] <= 13) ||
		str[i] == ' ' || (str[i] == '.' && str[i + 1] == '/')))
			return (NULL);
		i++;
	}
	while (str[i] && str[i] <= 126 && str[i] >= 32)
		i++;
	j = i;
	while (str[i] && str[i] != '\n')
		if (str[i] <= 126 && str[i++] >= 32)
			return (NULL);
	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	i = str[i - 1] == '.' ? i - 1 : i;
	j = j - i;
	b->path->ea = ft_substr(str, i, j);
	return (ft_control_texture(b->path->ea, b));
}

char	*ft_get_path_we(char *str, t_map *b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '/')
	{
		if (!((str[i] >= 9 && str[i] <= 13) ||
		str[i] == ' ' || (str[i] == '.' && str[i + 1] == '/')))
			return (NULL);
		i++;
	}
	while (str[i] && str[i] <= 126 && str[i] >= 32)
		i++;
	j = i;
	while (str[i] && str[i] != '\n')
		if (str[i] <= 126 && str[i++] >= 32)
			return (NULL);
	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	i = str[i - 1] == '.' ? i - 1 : i;
	j = j - i;
	b->path->we = ft_substr(str, i, j);
	return (ft_control_texture(b->path->we, b));
}

char	*ft_get_path_so(char *str, t_map *b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '/')
	{
		if (!((str[i] >= 9 && str[i] <= 13) ||
		str[i] == ' ' || (str[i] == '.' && str[i + 1] == '/')))
			return (NULL);
		i++;
	}
	while (str[i] && str[i] <= 126 && str[i] >= 32)
		i++;
	j = i;
	while (str[i] && str[i] != '\n')
		if (str[i] <= 126 && str[i++] >= 32)
			return (NULL);
	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	i = str[i - 1] == '.' ? i - 1 : i;
	j = j - i;
	b->path->so = ft_substr(str, i, j);
	return (ft_control_texture(b->path->so, b));
}

char	*ft_get_path_no(char *str, t_map *b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '/')
	{
		if (!((str[i] >= 9 && str[i] <= 13) ||
		str[i] == ' ' || (str[i] == '.' && str[i + 1] == '/')))
			return (NULL);
		i++;
	}
	while (str[i] && str[i] <= 126 && str[i] >= 32)
		i++;
	j = i;
	while (str[i] && str[i] != '\n')
		if (str[i] <= 126 && str[i++] >= 32)
			return (NULL);
	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	i = str[i - 1] == '.' ? i - 1 : i;
	j = j - i;
	b->path->no = ft_substr(str, i, j);
	return (ft_control_texture(b->path->no, b));
}

char	*ft_get_path_sp(char *str, t_map *b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '/')
	{
		if (!((str[i] >= 9 && str[i] <= 13) ||
		str[i] == ' ' || (str[i] == '.' && str[i + 1] == '/')))
			return (NULL);
		i++;
	}
	while (str[i] && str[i] <= 126 && str[i] >= 32)
		i++;
	j = i;
	while (str[i] && str[i] != '\n')
		if (str[i] <= 126 && str[i++] >= 32)
			return (NULL);
	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	i = str[i - 1] == '.' ? i - 1 : i;
	j = j - i;
	b->path->sp = ft_substr(str, i, j);
	return (ft_control_texture(b->path->sp, b));
}
