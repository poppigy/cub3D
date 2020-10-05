/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:46:47 by qcraghas          #+#    #+#             */
/*   Updated: 2020/09/30 22:46:50 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	conf_check(char *line, t_cub *data)
{
	while (*line == ' ')
		line++;
	if (*line == '\0')
		exit(ft_errors(ERR_EMPTY_CONFIG));
	if (*line == 'R')
		get_resolution(line + 1, data);
	else if (*line == 'F' || *line == 'C')
		get_color(line, data);
	else
		get_path(line, data);
}

void	get_config(int fd, t_cub *data)
{
	char	*line;
	int		code;

	while (data->scene.end > 0)
	{
		code = get_next_line(fd, &line, 0);
		if (code == -1)
			exit(ft_errors(ERR_MALLOC));
		if (code == 0)
			exit(ft_errors(ERR_CONFIG_EOF));
		if (*line != '\0')
			conf_check(line, data);
		free(line);
	}
}
