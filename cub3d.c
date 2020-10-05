/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <qcraghas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:58:42 by qcraghas          #+#    #+#             */
/*   Updated: 2020/08/25 12:41:23 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_argv_map(char *s)
{
	if (!s || ft_strlen(s) < 5)
		exit(ft_errors(ERR_MAP_FILE));
	s += ft_strlen(s) - 4;
	if (ft_strncmp(s, ".cub", 4))
		exit(ft_errors(ERR_MAP_FILE));
}

void	check_argv_save(char *s, t_cub *data)
{
	if (!s || ft_strlen(s) != 6)
		exit(ft_errors(ERR_SAVE));
	if (ft_strncmp(s, "--save", 6))
		exit(ft_errors(ERR_SAVE));
	data->save = 1;
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_cub	data;

	if (argc < 2 || argc > 3)
		exit(ft_errors(ERR_ARGS));
	check_argv_map(argv[1]);
	if (argv[2])
		check_argv_save(argv[2], &data);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit(ft_errors(ERR_MAP_FD));
	data_init(&data);
	map_scan(fd, &data);
	close(fd);
	image_put(&data);
	return (0);
}
