/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:49:15 by qcraghas          #+#    #+#             */
/*   Updated: 2020/10/04 00:14:02 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_errors_two(int code)
{
	if (code == ERR_BAD_TEXTURE_FILE)
		ft_putstr_fd("Error\nBad file or path to texture\n", 1);
	else if (code == ERR_RES_TEXTURE)
		ft_putstr_fd("Error\nNot compatible texture resolution\n", 1);
	else if (code == ERR_SECOND_PLAYER)
		ft_putstr_fd("Error\nTwo players on the map\n", 1);
	else if (code == ERR_PLAYER_NOT_FOUND)
		ft_putstr_fd("Error\nNo player on the map\n", 1);
	else if (code == ERR_MAP)
		ft_putstr_fd("Error\nBad map. You should feel bad\n", 1);
	else if (code == ERR_MAP_NOT_CLOSED)
		ft_putstr_fd("Error\nMap is not closed by walls\n", 1);
	else if (code == ERR_MLX)
		ft_putstr_fd("Error\nMLX error. The problem is on a french side\n", 1);
}

static void	ft_errors_one(int code)
{
	if (code == ERR_BAD_RES_DATA)
		ft_putstr_fd("Error\nBad resolution data\n", 1);
	else if (code == ERR_NOT_CONFIG)
		ft_putstr_fd("Error\nNot a proper config\n", 1);
	else if (code == ERR_EMPTY_CONFIG)
		ft_putstr_fd("Error\nConfig element is empty\n", 1);
	else if (code == ERR_RES_NOT_TWO)
		ft_putstr_fd("Error\nResolution must consist of two numbers\n", 1);
	else if (code == ERR_NEGATIVE_RES)
		ft_putstr_fd("Error\nResolution must be a positive number\n", 1);
	else if (code == ERR_DUPLICATED_CONF)
		ft_putstr_fd("Error\nDuplicated config\n", 1);
	else if (code == ERR_BAD_SPACING)
		ft_putstr_fd("Error\nNo space after identifier\n", 1);
	else if (code == ERR_NO_COLOR_DATA)
		ft_putstr_fd("Error\nNo any data for color\n", 1);
	else if (code == ERR_EXCESS_COLOR_DATA)
		ft_putstr_fd("Error\nToo much data for color\n", 1);
	else if (code == ERR_COLOR_NOT_IN_RANGE)
		ft_putstr_fd("Error\nRGB color must be in range [0;255]\n", 1);
	else if (code == ERR_NO_PATH_IN_CONFIG)
		ft_putstr_fd("Error\nNo path to texture in config\n", 1);
	else
		ft_errors_two(code);
}

int			ft_errors(int code)
{
	if (code == SAVE)
		ft_putstr_fd("'screenshot.bmp' was created\n", 1);
	else if (code == ESC_EXIT)
		ft_putstr_fd("Exit with escape\n", 1);
	else if (code == RED_BUTTON_EXIT)
		ft_putstr_fd("Exit with red button\n", 1);
	else if (code == ERR_MALLOC)
		ft_putstr_fd("Error\nmalloc() error\n", 1);
	else if (code == ERR_ARGS)
		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
	else if (code == ERR_MAP_FILE)
		ft_putstr_fd("Error\nWrong map extension\n", 1);
	else if (code == ERR_SAVE)
		ft_putstr_fd("Error\nUse '--save' to make screenshot\n", 1);
	else if (code == ERR_MAP_FD)
		ft_putstr_fd("Error\nBad file descriptor of the map\n", 1);
	else if (code == ERR_CONFIG_EOF)
		ft_putstr_fd("Error\nNot enough data to run a program\n", 1);
	else
		ft_errors_one(code);
	return (code * (-1));
}
