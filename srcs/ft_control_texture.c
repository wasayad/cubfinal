/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_control_texture.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 16:21:22 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 15:45:57 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_control_texture(char *str, t_map *b)
{
	int		fd;

	fd = open(str, O_WRONLY, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_printf(2, "Error\n-> Missing texture || Syntax error : %s\n", str);
		ft_exit(b);
	}
	close(fd);
	return ("hey");
}

void	instance_texture_01(t_map *b)
{
	if (!(b->imgno = mlx_xpm_file_to_image(b->data->mlx_ptr, b->path->no,
	&b->nowidth, &b->noheight)))
	{
		ft_printf(2, "Error\n-> Failed loading texture : %s\n", b->path->no);
		b->where = 2;
		ft_exit(b);
	}
	b->imgnod = (int *)mlx_get_data_addr(b->imgno,
	&b->bpp, &b->size_l, &b->endian);
	if (!(b->imgsu = mlx_xpm_file_to_image(b->data->mlx_ptr, b->path->so,
	&b->suwidth, &b->suheight)))
	{
		ft_printf(2, "Error\n-> Failed loading texture : %s\n", b->path->so);
		b->where = 3;
		ft_exit(b);
	}
	b->imgsud = (int *)mlx_get_data_addr(b->imgsu,
	&b->bpp, &b->size_l, &b->endian);
	instance_texture_02(b);
}

void	instance_texture_02(t_map *b)
{
	if (!(b->imgea = mlx_xpm_file_to_image(b->data->mlx_ptr, b->path->ea,
	&b->eawidth, &b->eaheight)))
	{
		ft_printf(2, "Error\n-> Failed loading texture : %s\n", b->path->ea);
		b->where = 4;
		ft_exit(b);
	}
	b->imgead = (int *)mlx_get_data_addr(b->imgea,
	&b->bpp, &b->size_l, &b->endian);
	if (!(b->imgwe = mlx_xpm_file_to_image(b->data->mlx_ptr, b->path->we,
	&b->wewidth, &b->weheight)))
	{
		ft_printf(2, "Error\n-> Failed loading texture : %s\n", b->path->we);
		b->where = 5;
		ft_exit(b);
	}
	b->imgwed = (int *)mlx_get_data_addr(b->imgwe,
	&b->bpp, &b->size_l, &b->endian);
}

void	control_draw(t_map *b)
{
	if (b->texx < 0)
		b->texx = 0;
	if (b->texy < 0)
		b->texy = 0;
}
