/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:08:13 by qcraghas          #+#    #+#             */
/*   Updated: 2020/10/04 15:18:12 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_start(t_cub *data)
{
	if (!(data->w.mlx = mlx_init()))
		exit(ft_errors(ERR_MALLOC));
	data->w.win = mlx_new_window(data->w.mlx, data->w.win_w,
			data->w.win_h, "-----SIMULATION-----");
	if (!data->w.win)
		exit(ft_errors(ERR_MALLOC));
	data->image.img = mlx_new_image(data->w.mlx, data->w.win_w,
									data->w.win_h);
	if (!data->image.img)
		exit(ft_errors(ERR_MALLOC));
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	if (!data->image.addr)
		exit(ft_errors(ERR_MALLOC));
}

void	string_to_screen(t_cub *data)
{
	char	*s;
	char	*p;
	int		x;
	int		y;

	s = ft_itoa(data->left_sprites);
	p = ft_strjoin("Sprites left: ", s);
	if (!s || !p)
		exit(ft_errors(ERR_MALLOC));
	x = 10;
	y = (int)(data->w.win_h * 0.95);
	mlx_string_put(data->w.mlx, data->w.win, x, y, 0x000000FF, p);
	free(s);
	free(p);
}

void	draw_screen(t_cub *data)
{
	pic_draw(data);
	draw_sprites(data);
	if (data->pic.expose_map == 1)
		map2d(data);
	mlx_put_image_to_window(data->w.mlx, data->w.win,
							data->image.img, 0, 0);
}

void	hook_and_loop(t_cub *data)
{
	if (mlx_hook(data->w.win, 2, 1L << 0, presskey, data) < 0)
		exit(ft_errors(ERR_MLX));
	mlx_hook(data->w.win, 17, 1L << 17, close_win, data);
	mlx_loop(data->w.mlx);
}

void	image_put(t_cub *data)
{
	if (data->save == 1)
		img_to_bmp(data);
	mlx_start(data);
	init_textures(data);
	draw_screen(data);
	hook_and_loop(data);
}
