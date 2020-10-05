/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:22:17 by qcraghas          #+#    #+#             */
/*   Updated: 2020/09/12 17:22:21 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win	win_init(void)
{
	t_win	window;

	window.mlx = NULL;
	window.win = NULL;
	window.x = 0.0;
	window.y = 0.0;
	window.win_h = 0;
	window.win_w = 0;
	window.scale = 0;
	window.ppc = 64;
	return (window);
}

t_img	img_init(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bits_per_pixel = 0;
	img.line_length = 0;
	img.endian = 0;
	return (img);
}

t_text	text_init(void)
{
	t_text	text;

	text.w = 0;
	text.h = 0;
	text.img = NULL;
	text.addr = 0;
	text.bits_per_pixel = 0;
	text.line_length = 0;
	text.endian = 0;
	return (text);
}

t_pic	pic_init(void)
{
	t_pic	pic;

	pic.ray_len = 0.0000;
	pic.ax = 0;
	pic.ay = 0;
	pic.ax_y = 0;
	pic.ay_y = 0;
	pic.t = 't';
	pic.t_y = 't';
	pic.expose_map = -1;
	return (pic);
}

void	data_init(t_cub *data)
{
	data->left_sprites = 0;
	data->scene = scene_init();
	data->pl = player_init();
	data->w = win_init();
	data->image = img_init();
	data->txt_north = text_init();
	data->txt_west = text_init();
	data->txt_south = text_init();
	data->txt_east = text_init();
	data->txt_sprite = text_init();
	data->pic = pic_init();
	data->sprites = NULL;
}
