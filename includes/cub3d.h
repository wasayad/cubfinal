/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wasayad <wasayad@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 15:50:18 by sayad        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 14:09:55 by wasayad     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdlib.h"
# include <unistd.h>
# include "stdio.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"

typedef struct	s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}				t_bpm;

typedef struct	s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bpm2;

typedef struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_color_s
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
}				t_color_s;

typedef	union	u_rgb
{
	int			color;
	t_color_s	rgb;
}				t_rgb;

typedef struct	s_res
{
	int		x;
	int		y;
}				t_res;

typedef struct	s_path
{
	char *no;
	char *ea;
	char *we;
	char *so;
	char *sp;
}				t_path;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_map
{
	t_data		*data;
	t_path		*path;
	t_rgb		*color;
	t_res		*res;
	t_sprite	*sprite;

	char		*temp1;
	char		*temp;
	char		*map;
	char		**area;

	double		posx;
	double		posy;

	int			mapx;
	int			mapy;

	double		dirx;
	double		diry;

	double		camerax;
	double		cameray;

	double		planex;
	double		planey;

	double		raydirx;
	double		raydiry;

	int			len;

	double		time;
	double		oldtime;

	double		sidedistx;
	double		sidedisty;

	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		wallx;
	double		step;
	double		texpos;
	int			texx;
	int			texy;

	int			stepx;
	int			stepy;

	int			hit;
	int			side;

	int			lineheight;
	int			drawstart;
	int			drawend;

	double		movespeed;
	double		rotspeed;

	double		oldirx;
	double		oldplanex;

	void		*imgptr;
	int			*imgdata;
	int			bpp;
	int			endian;
	int			size_l;

	int			color_g;
	int			color_s;

	void		*imgno;
	int			*imgnod;
	int			nowidth;
	int			noheight;

	void		*imgsu;
	int			*imgsud;
	int			suwidth;
	int			suheight;

	void		*imgea;
	int			*imgead;
	int			eawidth;
	int			eaheight;

	void		*imgwe;
	int			*imgwed;
	int			wewidth;
	int			weheight;

	void		*imgsp;
	int			*imgspd;
	int			spwidth;
	int			spheight;

	double		invdet;
	double		transx;
	double		transy;
	double		spx;
	double		spy;
	double		spritex;
	double		spritey;

	int			spscreenx;
	int			sph;
	int			drawstarty;
	int			drawendy;
	int			spw;
	int			drawstartx;
	int			drawendx;
	size_t		d;
	int			colori;
	int			numsprite;
	int			where;
	int			screenshot;
	double		*spdist;
	int			*spriteorder;
	int			texture_check;
	double		*zbuffer;
}				t_map;

char			*ft_del_line(t_map *b, char *c);
int				ft_get_resolution(char *str, t_map *b);
int				ft_get_color_ground(char *str, t_map *b);
int				ft_get_color_sky(char *str, t_map *b);
int				ft_control_value_color_s(t_map *b, int i);
int				ft_control_value_color_g(t_map *b, int i);
int				ft_check_map(t_map *b);
void			ft_check_map_01(t_map *b);
void			ft_check_map_02(t_map *b);
int				ft_check_area(char *m, t_map *b);
char			*ft_get_path_ea(char *str, t_map *b);
char			*ft_get_path_no(char *str, t_map *b);
char			*ft_get_path_we(char *str, t_map *b);
char			*ft_get_path_so(char *str, t_map *b);
char			*ft_get_path_sp(char *str, t_map *b);
void			step_compt(t_map *b);
void			ft_hit(t_map *b);
void			ft_lineheight(t_map *b);
int				compt_case(t_map *b);
void			draw_sky_ground(t_map *b);
int				gere_key(int keycode, void *param);
int				rotate_right(t_map *b);
int				rotate_left(t_map *b);
int				move_back(t_map *b);
int				move_front(t_map *b);
void			ft_exit(void *param);
t_map			*init_struct(void);
void			ft_init_fov(t_map *b);
void			ft_calculate_texture(t_map *b);
void			ft_calculate_texture_ea(t_map *b);
void			ft_calculate_texture_su(t_map *b);
void			ft_calculate_texture_no(t_map *b);
void			ft_calculate_texture_we(t_map *b);
t_sprite		*ft_create_substruct(t_map *b, double x, double y);
int				ft_realloc_struct(t_map *b, double y, double x);
void			ft_calculate_sprite(t_map *b, int i);
void			ft_draw_sprite(t_map *b);
int				ft_main_loop(t_map *b);
int				p(void *param);
void			init_ray(t_map *b);
int				instance_texture(t_map *b);
void			ft_save_bitmap(const char *filename, t_map *c);
void			ft_check_line(t_map *b);
int				ft_index(char *str, int i);
void			ft_control_res(t_map *b);
void			ft_calculate_sort_dist(t_map *b);
void			ft_exit_01(t_map *b);
void			ft_free_tab(t_map *b);
void			ft_calculate_sprite_dist(t_map *b);
int				ft_hint_object(t_map *b, double addx, double addy);
int				ft_init_struct_01(t_map *b);
int				move_side_right(t_map *b);
int				move_side_left(t_map *b);
void			ft_check_map_03(t_map *b);
void			ft_check_map_04(t_map *b);
int				ft_atoi_color(const char *str);
char			*ft_delete_space(char *str);
char			**ft_delete_space_01(char *str, char *tmp);
void			ft_check_map_05(t_map *b);
void			ft_check_map_06(t_map *b);
char			*ft_control_texture(char *str, t_map *b);
void			instance_texture_01(t_map *b);
void			instance_texture_02(t_map *b);
void			control_draw(t_map *b);
void			ft_check_map_07(t_map *b);
void			ft_init_struct_nul(t_map *b);
void			ft_check_map_07(t_map *b);
void			ft_free(void **f);
void			ft_control_map_name(char **ag, t_map *b);
int				ft_norme(char *m, t_map *b);
char			*check_character(char *m, t_map *b);

#endif
