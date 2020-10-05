/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:56:00 by qcraghas          #+#    #+#             */
/*   Updated: 2020/08/26 18:56:02 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			zero_check(int i, int j, t_cub *data)
{
	if (data->scene.map[i][j] == ' ' || data->scene.map[i][j] == '1')
		return (SUCCESS);
	if (data->scene.map[i + 1][j] == ' ')
		exit(ft_errors(ERR_MAP_NOT_CLOSED));
	if (data->scene.map[i][j + 1] == ' ')
		exit(ft_errors(ERR_MAP_NOT_CLOSED));
	if (data->scene.map[i][j - 1] == ' ')
		exit(ft_errors(ERR_MAP_NOT_CLOSED));
	if (data->scene.map[i - 1][j] == ' ')
		exit(ft_errors(ERR_MAP_NOT_CLOSED));
	return (SUCCESS);
}

static void	map_scale(t_win *win, t_scene *s)
{
	int map_max_side;
	int screen_max_side;

	map_max_side = s->map_x > s->map_y + 2 ? s->map_x : s->map_y + 2;
	screen_max_side = win->win_h > win->win_w ? win->win_h : win->win_w;
	win->scale = (screen_max_side / map_max_side) / 3;
}

void		get_player(int x, int y, t_cub *data)
{
	map_scale(&data->w, &data->scene);
	if (data->pl.pos == ' ')
	{
		data->pl.pos = data->scene.map[y][x];
		data->pl.pos_x = x * data->w.ppc + data->w.ppc / 2;
		data->pl.pos_y = y * data->w.ppc + data->w.ppc / 2;
	}
	else
		exit(ft_errors(ERR_SECOND_PLAYER));
	if (data->pl.pos == 'N')
		data->pl.angle = 3 * M_PI_2;
	else if (data->pl.pos == 'W')
		data->pl.angle = M_PI;
	else if (data->pl.pos == 'S')
		data->pl.angle = M_PI_2;
	else if (data->pl.pos == 'E')
		data->pl.angle = 0;
}

void		map_valid(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->scene.map_y < 3)
		exit(ft_errors(ERR_MAP));
	while (++i <= data->scene.map_y)
	{
		j = 0;
		while (++j < data->scene.map_x)
		{
			if (!ft_strchr(" 012NWSE", data->scene.map[i][j]))
				exit(ft_errors(ERR_MAP));
			if (ft_strchr("NWSE", data->scene.map[i][j]))
				get_player(j, i, data);
			if (data->scene.map[i][j] == '2')
				sprites(j, i, data);
			zero_check(i, j, data);
		}
	}
	sprites_dist(data);
	if (data->pl.pos == ' ')
		exit(ft_errors(ERR_PLAYER_NOT_FOUND));
}
