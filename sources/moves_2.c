#include "../include/cub3d.h"

void	move_forward(t_cube *cube)
{
	cube->posy += MS * cube->diry;
	cube->posx += MS * cube->dirx;
}

void	move_backward(t_cube *cube)
{
	cube->posy -= MS * cube->diry;
	cube->posx -= MS * cube->dirx;
}

void	move_left(t_cube *cube)
{
	cube->posy -= MS * cube->planey;
	cube->posx -= MS * cube->planex;
}

void	move_right(t_cube *cube)
{
	cube->posy += MS * cube->planey;
	cube->posx += MS * cube->planex;
}

void	move(t_cube *cube)
{
	if (cube->key->w)
		move_forward(cube);
	if (cube->key->s)
		move_backward(cube);
	if (cube->key->right)
		rot_right(cube);
	if (cube->key->left)
		rot_left(cube);
	if (cube->key->a)
		move_left(cube);
	if (cube->key->d)
		move_right(cube);
}
