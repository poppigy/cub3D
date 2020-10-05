/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 23:28:34 by qcraghas          #+#    #+#             */
/*   Updated: 2020/10/03 23:28:36 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_sprite(t_cub *data, int x, int y)
{
	t_s	*t;

	t = data->sprites;
	while (t)
	{
		if (((t->sprite_x - 32) / 64 == x) && ((t->sprite_y - 32) / 64 == y))
		{
			data->scene.map[y][x] = '0';
			t->collect = 0;
			break ;
		}
		t = t->next;
	}
}

void	field_swap(t_s **sort, t_s **sprites)
{
	double	x;
	double	y;
	double	dist;
	double	angle;
	int		collect;

	x = (*sort)->sprite_x;
	y = (*sort)->sprite_y;
	dist = (*sort)->dist;
	angle = (*sort)->angle;
	collect = (*sort)->collect;
	(*sort)->sprite_x = (*sprites)->sprite_x;
	(*sort)->sprite_y = (*sprites)->sprite_y;
	(*sort)->dist = (*sprites)->dist;
	(*sort)->angle = (*sprites)->angle;
	(*sort)->collect = (*sprites)->collect;
	(*sprites)->sprite_x = x;
	(*sprites)->sprite_y = y;
	(*sprites)->dist = dist;
	(*sprites)->angle = angle;
	(*sprites)->collect = collect;
}

void	sort_sprites(t_s *sprites)
{
	t_s	*sort;

	if (sprites != NULL)
	{
		while (sprites->next != NULL)
		{
			sort = sprites->next;
			while (sort != NULL)
			{
				if (sort->dist > sprites->dist)
					field_swap(&sort, &sprites);
				sort = sort->next;
			}
			sprites = sprites->next;
		}
	}
}
