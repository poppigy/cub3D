/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:59:09 by qcraghas          #+#    #+#             */
/*   Updated: 2020/09/27 13:59:11 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites(int x, int y, t_cub *data)
{
	double sprite_x;
	double sprite_y;

	sprite_x = x * 64 + 32;
	sprite_y = y * 64 + 32;
	ft_lst_sp(&data->sprites, ft_sp_new(sprite_x, sprite_y));
}

void	sprites_dist(t_cub *data)
{
	t_s		*d;
	double	dy;
	double	dx;

	d = data->sprites;
	while (d)
	{
		dy = d->sprite_y - data->pl.pos_y;
		dx = d->sprite_x - data->pl.pos_x;
		d->dist = sqrt(pow(dx, 2) + pow(dy, 2));
		d->angle = atan2(dy, dx) - data->pl.angle;
		while (d->angle < 0)
			d->angle += 2 * M_PI;
		while (d->angle > 2 * M_PI)
			d->angle -= 2 * M_PI;
		d = d->next;
	}
	sort_sprites(data->sprites);
}

void	sprites_color(t_cub *d, double sprite, t_s *s)
{
	int		c;
	double	x;
	double	y;
	int		i;
	int		j;

	x = (s->angle) * (d->w.win_w / d->pl.fov) + (d->w.win_w / 2) - sprite / 2;
	y = d->w.win_h / 2 - sprite / 2;
	i = -1;
	while (++i < sprite && s->dist > 24)
	{
		j = -1;
		if (x + i < 0 || x + i >= d->w.win_w)
			continue;
		if (d->pic.arr[(int)(x + i)] > s->dist)
		{
			while (++j < sprite)
			{
				if (y + j < 0 || y + j >= d->w.win_h)
					continue;
				(c = sprite_texture(d, sprite, i, j)) > 0 ?
					my_mlx_pixel_put(d, (int)(x + i), (int)(y + j), c) : 0;
			}
		}
	}
}

void	draw_sprites(t_cub *data)
{
	t_s		*s;
	double	sprite;

	s = data->sprites;
	sprites_dist(data);
	data->left_sprites = 0;
	while (s)
	{
		if (s->collect == 0)
		{
			s = s->next;
			continue ;
		}
		sprite = s->dist * (data->w.ppc / 5);
		sprite = (data->pl.viewport / sprite) * data->w.win_h;
		while (s->angle < (-1) * M_PI)
			s->angle += 2 * M_PI;
		while (s->angle > M_PI)
			s->angle -= 2 * M_PI;
		sprites_color(data, sprite, s);
		data->left_sprites++;
		s = s->next;
	}
	free(data->pic.arr);
}
