/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:26:04 by qcraghas          #+#    #+#             */
/*   Updated: 2020/08/24 19:29:42 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*add_spaces(char *line)
{
	char	*right;
	char	*left;

	left = ft_strjoin(" ", line);
	right = ft_strjoin(left, " ");
	if (!right || !left)
		exit(ft_errors(ERR_MALLOC));
	free(line);
	free(left);
	return (right);
}

void		get_list(int fd, t_list **l_map, t_cub *data)
{
	int		bwr;
	char	*line;
	int		end_map;

	end_map = 0;
	while ((bwr = get_next_line(fd, &line, 1)) >= 0)
	{
		if (*line == '\0')
			end_map = 1;
		if (*line != '\0' && end_map == 1)
			exit(ft_errors(ERR_MAP));
		line = add_spaces(line);
		ft_lstadd_back(l_map, ft_lstnew(line));
		if (!l_map)
			exit(ft_errors(ERR_MALLOC));
		if (data->scene.map_x < (int)ft_strlen(line))
			data->scene.map_x = (int)ft_strlen(line);
		data->scene.map_y++;
		if (bwr == 0)
			break ;
	}
}

void		compose(int fd, t_list **l_map, t_cub *data)
{
	get_list(fd, l_map, data);
	map_fill(l_map, data->scene.map_x);
	data->scene.map = map_make(l_map, data->scene.map_x);
}

void		get_map(int fd, t_cub *data)
{
	t_list	*l_map;
	char	*line;

	l_map = NULL;
	while (get_next_line(fd, &line, 1) > 0)
	{
		if (*line != '\0')
		{
			line = add_spaces(line);
			ft_lstadd_back(&l_map, ft_lstnew(line));
			if (!l_map)
				exit(ft_errors(ERR_MALLOC));
			if (data->scene.map_x < (int)ft_strlen(line))
				data->scene.map_x = (int)ft_strlen(line);
			data->scene.map_y++;
			break ;
		}
		free(line);
	}
	compose(fd, &l_map, data);
}

void		map_scan(int fd, t_cub *data)
{
	get_config(fd, data);
	get_map(fd, data);
	map_valid(data);
}
