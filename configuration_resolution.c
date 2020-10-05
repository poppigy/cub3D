/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:41:31 by qcraghas          #+#    #+#             */
/*   Updated: 2020/08/25 12:41:33 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	limit_res(t_cub *data, int max_x, int max_y)
{
	if (data->w.win_w > max_x)
		data->w.win_w = max_x;
	if (data->w.win_w < 320)
		data->w.win_w = 320;
	if (data->w.win_h > max_y)
		data->w.win_h = max_y;
	if (data->w.win_h < 240)
		data->w.win_h = 240;
	data->scene.end--;
	ft_putstr_fd("Resolution: width - ", 1);
	ft_putnbr_fd(data->w.win_w, 1);
	ft_putstr_fd(", height - ", 1);
	ft_putnbr_fd(data->w.win_h, 1);
	ft_putstr_fd("\n", 1);
}

void		get_resolution(char *s, t_cub *data)
{
	char	**res;
	int		max_x;
	int		max_y;

	if (data->w.win_h != 0 || data->w.win_w != 0)
		exit(ft_errors(ERR_DUPLICATED_CONF));
	if (*s != ' ')
		exit(ft_errors(ERR_BAD_SPACING));
	while (*s == ' ')
		s++;
	if (*s == '\0' || !ft_isdigit(*s))
		exit(ft_errors(ERR_BAD_RES_DATA));
	res = ft_split(s, ' ');
	if (array_size(res) != 2)
		exit(ft_errors(ERR_RES_NOT_TWO));
	if ((data->w.win_w = ft_atoi(res[0])) <= 0 ||
		(data->w.win_h = ft_atoi(res[1])) <= 0)
		exit(ft_errors(ERR_NEGATIVE_RES));
	array_free(res);
	mlx_get_screen_size(data->w.mlx, &max_x, &max_y);
	limit_res(data, max_x, max_y);
}
