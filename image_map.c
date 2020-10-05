#include "cub3d.h"

static void	draw_player(t_cub *data)
{
	int x;
	int y;
	int i;
	int j;

	x = (int)((data->pl.pos_x / 64) * data->w.scale);
	y = (int)((data->pl.pos_y / 64) * data->w.scale);
	i = -1;
	while (++i < data->w.scale / 2)
	{
		j = -1;
		while (++j < data->w.scale / 2)
			my_mlx_pixel_put(data, x + i, y + j, 0x00FF0000);
	}
}

void		map2d(t_cub *data)
{
	int scale;
	int x;
	int y;

	scale = data->w.scale;
	y = -2;
	while (++y / scale <= data->scene.map_y + 1)
	{
		x = -2;
		while (++x / scale < data->scene.map_x)
		{
			if (ft_strchr("0NSWE", data->scene.map[y / scale][x / scale]))
				my_mlx_pixel_put(data, x + 1, y + 1, 0x00F8F8FF);
			else if (data->scene.map[y / (scale)][x / scale] == '2')
				my_mlx_pixel_put(data, x + 1, y + 1, 0x0000FF00);
			else if (data->scene.map[y / scale][x / scale] == '1')
				my_mlx_pixel_put(data, x + 1, y + 1, 0x000000FF);
			else if (data->scene.map[y / scale][x / scale] == ' ')
				my_mlx_pixel_put(data, x + 1, y + 1, 0x00FFC0CB);
		}
	}
	draw_player(data);
	mlx_put_image_to_window(data->w.mlx, data->w.win,
							data->image.img, 0, 0);
}
