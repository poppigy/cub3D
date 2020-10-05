/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:35:27 by qcraghas          #+#    #+#             */
/*   Updated: 2020/10/04 14:33:14 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "sources/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define TURN_R 124
# define TURN_L 123

enum			e_errors
{
	SUCCESS = 0,
	SAVE = -200,
	ESC_EXIT,
	RED_BUTTON_EXIT,
	ERR_MALLOC = -100,
	ERR_ARGS,
	ERR_MAP_FILE,
	ERR_SAVE,
	ERR_MAP_FD,
	ERR_CONFIG_EOF,
	ERR_NOT_CONFIG,
	ERR_EMPTY_CONFIG,
	ERR_BAD_RES_DATA,
	ERR_RES_NOT_TWO,
	ERR_NEGATIVE_RES,
	ERR_DUPLICATED_CONF,
	ERR_BAD_SPACING,
	ERR_NO_COLOR_DATA,
	ERR_EXCESS_COLOR_DATA,
	ERR_COLOR_NOT_IN_RANGE,
	ERR_NO_PATH_IN_CONFIG,
	ERR_BAD_TEXTURE_FILE,
	ERR_RES_TEXTURE,
	ERR_SECOND_PLAYER,
	ERR_PLAYER_NOT_FOUND,
	ERR_MAP,
	ERR_MAP_NOT_CLOSED,
	ERR_MLX
};

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}				t_img;

typedef struct	s_player
{
	char		pos;
	double		angle;
	double		fov;
	double		pos_x;
	double		pos_y;
	double		viewport;
}				t_player;

typedef struct	s_scene
{
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	char		*sprite;
	int			floor;
	int			ceiling;
	int			end;
	char		**map;
	int			map_x;
	int			map_y;
}				t_scene;

typedef struct	s_win {
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	int			win_h;
	int			win_w;
	double		ppc;
	int			scale;
}				t_win;

typedef struct	s_pic
{
	double		ray_len;
	double		ax;
	double		ay;
	double		ax_y;
	double		ay_y;
	char		t;
	char		t_y;
	double		*arr;
	int			expose_map;
}				t_pic;

typedef struct	s_text
{
	int			w;
	int			h;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_text;

typedef struct	s_s
{
	double		sprite_x;
	double		sprite_y;
	double		dist;
	double		angle;
	int			collect;
	struct s_s	*next;
}				t_s;

typedef struct	s_ray
{
	double		dx;
	double		dy;
	double		ax;
	double		ay;
	double		x;
	double		y;
}				t_ray;

typedef struct	s_cub
{
	int			save;
	int			left_sprites;
	t_scene		scene;
	t_player	pl;
	t_win		w;
	t_img		image;
	t_pic		pic;
	t_text		txt_north;
	t_text		txt_west;
	t_text		txt_south;
	t_text		txt_east;
	t_text		txt_sprite;
	t_s			*sprites;
	t_ray		r_x;
	t_ray		r_y;
}				t_cub;

void			data_init(t_cub	*data);
t_scene			scene_init(void);
t_player		player_init(void);
t_win			win_init(void);
t_text			text_init(void);
t_img			img_init(void);
t_pic			pic_init(void);
void			map_scan(int fd, t_cub *data);
void			get_config(int fd, t_cub *data);
void			get_map(int fd, t_cub *data);
void			get_list(int fd, t_list **l_map, t_cub *data);
void			map_fill(t_list **map, size_t len);
char			*map_add(char *content, int c);
char			**map_make(t_list **map, int len);
char			*add_empty(int len);
void			conf_check(char *line, t_cub *data);
void			get_resolution(char *s, t_cub *data);
void			get_color(char *s, t_cub *data);
void			get_path(char *s, t_cub *data);
void			map_valid(t_cub *data);
void			get_player(int x, int y, t_cub *data);
void			my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void			image_put(t_cub *data);
void			pic_draw(t_cub *d);
double			intersect_x(t_cub *data, double angle);
double			intersect_y(t_cub *data, double angle);
void			line_draw(t_cub *d, double angle, int x);
int				get_texture_color(t_cub *data, double wall, int i);
void			map2d(t_cub *data);
int				presskey(int keycode, t_cub *data);
int				close_win(t_cub *data);
void			get_textures(t_win *window, char *text, t_text *t);
int				texture(t_text text, double height, int y, int x);
int				sprite_texture(t_cub *data, double sprite, double x, double y);
int				south_texture(t_cub *data, double wall, int i);
int				north_texture(t_cub *data, double wall, int i);
int				west_texture(t_cub *data, double wall, int i);
int				east_texture(t_cub *data, double wall, int i);
t_s				*ft_sp_new(double x, double y);
void			ft_lst_sp(t_s **sprite, t_s *new);
void			sprites(int x, int y, t_cub *data);
void			sprites_dist(t_cub *data);
void			sort_sprites(t_s *sprites);
void			draw_sprites(t_cub *data);
void			remove_sprite(t_cub *data, int x, int y);
void			string_to_img(t_cub *data);
void			raycasting(t_cub *data, double ray_angle);
void			hook_and_loop(t_cub *data);
void			img_to_bmp(t_cub *data);
void			draw_screen(t_cub *data);
void			init_textures(t_cub *data);
void			mlx_start(t_cub *data);
int				ft_errors(int code);
int				array_size(char **array);
int				array_free(char **array);

#endif
