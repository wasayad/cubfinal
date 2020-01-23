/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:53:17 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:14:41 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			p(void *param)
{
	t_map *b;

	b = param;
	ft_exit(b);
	return (1);
}

static void	control_screenshot_and_map_file(int ac, char **ag, t_map *b)
{
	if (ac == 3)
	{
		if (ft_strncmp(ag[2], "-save", ft_strlen("-save")) == 0)
		{
			b->screenshot = 1;
		}
		else
		{
			ft_printf(2, "Error\n-> Third argument is false only '-save'");
			ft_printf(2, " is allowed\n");
			ft_exit(b);
		}
	}
	b->where = 0;
	b->color->rgb.a = 0;
	if (!(b->map = ft_filetostring(ag[1])))
	{
		ft_printf(2, "Error\n-> wrong map file\n");
		ft_exit(b);
	}
	else if (ac > 3)
	{
		ft_printf(2, "Error\n-> A maximum of two arguments authorized\n");
		ft_exit(b);
	}
}

static int	check_index_after_map(t_map *b)
{
	int		i;

	i = 0;
	while (b->map[i])
		i++;
	i--;
	while (i > 0)
	{
		if (b->map[i] != '2' && b->map[i] != '0' && b->map[i] != '1'
		&& b->map[i] != 'N' && b->map[i] != 'S' &&
		b->map[i] != 'E' && b->map[i] != 'W' && b->map[i] != '\n'
		&& b->map[i] != ' ')
		{
			ft_printf(2, "Error\n-> Invalid character at the ");
			ft_printf(2, "end of the map file\n");
			ft_exit(b);
		}
		if (i > 0 && b->map[i] == '\n' && b->map[i + 1]
		== '1' && b->map[i - 1] == '1')
			return (1);
		i--;
	}
	return (1);
}

int			ft_main_loop(t_map *b)
{
	init_ray(b);
	if (b->screenshot == 1)
	{
		if ((b->data->mlx_win = mlx_new_window(b->data->mlx_ptr,
		0, 0, "cub3D")) == NULL)
			return (EXIT_FAILURE);
	}
	else
	{
		if ((b->data->mlx_win = mlx_new_window(b->data->mlx_ptr,
						b->res->x, b->res->y, "cub3D")) == NULL)
			return (EXIT_FAILURE);
	}
	b->where = 1;
	instance_texture(b);
	compt_case(b);
	mlx_hook(b->data->mlx_win, 2, 0, gere_key, b);
	mlx_hook(b->data->mlx_win, 17, 0, p, b);
	mlx_loop(b->data->mlx_ptr);
	return (1);
}

int			main(int ac, char **ag)
{
	t_map	*b;
	int		i;

	i = 0;
	if (ac < 2)
	{
		ft_printf(2, "Error\n-> put a map file as second argument\n");
		return (0);
	}
	if (!(b = init_struct()))
		return (0);
	ft_control_map_name(ag, b);
	control_screenshot_and_map_file(ac, ag, b);
	check_index_after_map(b);
	if (!(ft_check_map(b)))
		ft_exit(b);
	if ((b->data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	ft_main_loop(b);
	return (EXIT_SUCCESS);
}
