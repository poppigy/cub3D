#include "cub3d.h"

static int	rgb_bitwise(t_cub *data, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit(ft_errors(ERR_COLOR_NOT_IN_RANGE));
	array_free(rgb);
	data->scene.end--;
	return (0 << 24 | r << 16 | g << 8 | b);
}

static void	color_msg(char element, t_cub *data)
{
	char	*s;

	if (element == 'F')
	{
		ft_putstr_fd("Floor color: 0x", 1);
		if (!(s = ft_itoa_hex(data->scene.floor, 'X')))
			exit(ft_errors(ERR_MALLOC));
		ft_putstr_fd(s, 1);
		ft_putstr_fd("\n", 1);
	}
	if (element == 'C')
	{
		ft_putstr_fd("Ceiling color: 0x", 1);
		if (!(s = ft_itoa_hex(data->scene.ceiling, 'X')))
			exit(ft_errors(ERR_MALLOC));
		ft_putstr_fd(s, 1);
		ft_putstr_fd("\n", 1);
	}
	free(s);
}

void		check_commas(char *s)
{
	int commas;

	commas = 0;
	while (*s != '\0')
	{
		if (*s == ',')
			commas++;
		s++;
	}
	if (commas != 2)
		exit(ft_errors(ERR_NOT_CONFIG));
}

void		get_color(char *s, t_cub *data)
{
	char	**rgb;
	char	el;

	el = *s++;
	if (*s != ' ')
		exit(ft_errors(ERR_BAD_SPACING));
	while (*s == ' ')
		s++;
	if (*s == '\0')
		exit(ft_errors(ERR_NO_COLOR_DATA));
	check_commas(s);
	rgb = ft_split(s, ',');
	if (array_size(rgb) != 3)
		exit(ft_errors(ERR_EXCESS_COLOR_DATA));
	if (el == 'F')
		data->scene.floor = rgb_bitwise(data, rgb);
	if (el == 'C')
		data->scene.ceiling = rgb_bitwise(data, rgb);
	color_msg(el, data);
}
