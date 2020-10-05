#include "cub3d.h"

t_scene		scene_init(void)
{
	t_scene	scene;

	scene.n_texture = NULL;
	scene.s_texture = NULL;
	scene.w_texture = NULL;
	scene.e_texture = NULL;
	scene.sprite = NULL;
	scene.floor = -1;
	scene.ceiling = -1;
	scene.end = 8;
	scene.map = NULL;
	scene.map_x = 0;
	scene.map_y = 0;
	return (scene);
}

t_player	player_init(void)
{
	t_player	player;

	player.pos = ' ';
	player.angle = 0.0;
	player.fov = M_PI / 3;
	player.pos_x = 0;
	player.pos_y = 0;
	player.viewport = 0;
	return (player);
}
