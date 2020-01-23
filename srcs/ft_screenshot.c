/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_screenshot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 10:33:09 by wasayad      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:12:02 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_bitmap_image(t_map *c, int fd, t_bpm2 bitinf)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bitinf, sizeof(bitinf));
	y = c->res->y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->res->x)
		{
			ble = c->imgdata[y * c->res->x + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
	close(fd);
	ft_exit(c);
}

void			ft_save_bitmap(const char *filename, t_map *c)
{
	int			fd;
	t_bpm		bitheader;
	t_bpm2		bitinf;

	ft_memcpy(&bitheader.bitmap_type, "BM", 2);
	bitheader.file_size = c->res->x * c->res->y * 4 + 54;
	bitheader.reserved1 = 0;
	bitheader.reserved2 = 0;
	bitheader.offset_bits = 0;
	bitinf.size_header = sizeof(bitinf);
	bitinf.width = c->res->x;
	bitinf.height = c->res->y;
	bitinf.planes = 1;
	bitinf.bit_count = 24;
	bitinf.compression = 0;
	bitinf.image_size = c->res->x * c->res->y * 4 + 54;
	bitinf.ppm_x = 2;
	bitinf.ppm_y = 2;
	bitinf.clr_used = 0;
	bitinf.clr_important = 0;
	fd = open(filename, O_RDONLY | O_CREAT, S_IRWXU);
	close(fd);
	fd = open(filename, O_RDWR);
	write(fd, &bitheader, 14);
	ft_bitmap_image(c, fd, bitinf);
}
