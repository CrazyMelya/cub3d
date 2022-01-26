#include "../bonus_include/cub3d.h"

void	use(t_cube *cube)
{
	if (cube->map[(int)(cube->posx + cube->dirx)] \
		[(int)(cube->posy + cube->diry)] == '2')
		cube->map[(int)(cube->posx + cube->dirx)] \
		[(int)(cube->posy + cube->diry)] = '3';
	else if (cube->map[(int)(cube->posx + cube->dirx)] \
		[(int)(cube->posy + cube->diry)] == '3')
		cube->map[(int)(cube->posx + cube->dirx)] \
		[(int)(cube->posy + cube->diry)] = '2';
}

void	change_scale(t_cube *cube)
{
	if (cube->map_scale == 0.01)
		cube->map_scale = 0.003;
	else
		cube->map_scale = 0.01;
}

int	key_press(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 1;
	if (key == 1)
		cube->key->s = 1;
	if (key == 0)
		cube->key->a = 1;
	if (key == 2)
		cube->key->d = 1;
	if (key == 123)
		cube->key->left = 1;
	if (key == 124)
		cube->key->right = 1;
	if (key == 14)
		use(cube);
	if (key == 53)
		closer();
	if (key == 12)
		change_scale(cube);
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 0;
	if (key == 1)
		cube->key->s = 0;
	if (key == 0)
		cube->key->a = 0;
	if (key == 2)
		cube->key->d = 0;
	if (key == 123)
		cube->key->left = 0;
	if (key == 124)
		cube->key->right = 0;
	return (0);
}
