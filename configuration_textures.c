/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcraghas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:51:06 by qcraghas          #+#    #+#             */
/*   Updated: 2020/09/30 22:51:09 by qcraghas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		t_path(t_cub *data, char *path, char t)
{
	if (t == 'N' && data->scene.n_texture == NULL)
		data->scene.n_texture = path;
	else if (t == 'W' && data->scene.w_texture == NULL)
		data->scene.w_texture = path;
	else if (t == 'E' && data->scene.e_texture == NULL)
		data->scene.e_texture = path;
	else if (t == 'S' && data->scene.s_texture == NULL)
		data->scene.s_texture = path;
	else if (t == 'Z' && data->scene.sprite == NULL)
		data->scene.sprite = path;
	else
		exit(ft_errors(ERR_DUPLICATED_CONF));
}

static char	current_texture(char *s)
{
	int		i;
	char	*text[5];
	char	t;

	i = -1;
	text[0] = "NO";
	text[1] = "SO";
	text[2] = "WE";
	text[3] = "EA";
	text[4] = "S ";
	t = (*s == 'S') ? 'S' : 'x';
	while (++i < 5)
	{
		if (!ft_strncmp(s, text[i], 2))
		{
			t = *text[i];
			break ;
		}
		if (!ft_strncmp(s, text[4], 2))
		{
			t = 'Z';
			break ;
		}
	}
	return (t);
}

void		get_path(char *s, t_cub *data)
{
	int		i;
	char	*path;
	char	texture;

	texture = current_texture(s);
	if (ft_strchr("NSWE", texture))
		s += 2;
	if (texture == 'Z')
		s++;
	if (texture == 'x')
		exit(ft_errors(ERR_NOT_CONFIG));
	if (*s != ' ')
		exit(ft_errors(ERR_BAD_SPACING));
	while (*s == ' ')
		s++;
	if (!(i = ft_strlen(s)))
		exit(ft_errors(ERR_NO_PATH_IN_CONFIG));
	while (s[i - 1] == ' ')
		i--;
	if (!(path = ft_substr(s, 0, i)))
		exit(ft_errors(ERR_MALLOC));
	t_path(data, path, texture);
	data->scene.end--;
}
