#include "../bonus_include/cub3d.h"

int	can_move(int x, int y)
{
	if (worldMap[x][y] == 0 || worldMap[x][y] == 2)
		return (1);
	return (0);
}

void	rot_left(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->dirx;
	cube->dirx = cube->dirx \
	* cos(RS) - cube->diry * sin(RS);
	cube->diry = old_dir_x * sin(RS) + cube->diry * cos(RS);
	old_plane_x = cube->planex;
	cube->planex = cube->planex \
	* cos(RS) - cube->planey * sin(RS);
	cube->planey = old_plane_x * sin(RS) \
	+ cube->planey * cos(RS);
}

void	rot_right(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->dirx;
	cube->dirx = cube->dirx \
	* cos(-RS) + cube->diry * sin(RS);
	cube->diry = old_dir_x * sin(-RS) + cube->diry * cos(-RS);
	old_plane_x = cube->planex;
	cube->planex = cube->planex \
	* cos(-RS) + cube->planey * sin(RS);
	cube->planey = old_plane_x * sin(-RS) \
	+ cube->planey * cos(-RS);
}

void	move_forward(t_cube *cube)
{
	if (can_move(cube->posx, cube->posy + cube->diry))
		cube->posy += MS * cube->diry;
	if (can_move(cube->posx + cube->dirx, cube->posy))
		cube->posx += MS * cube->dirx;
}

void	move_backward(t_cube *cube)
{
	if (can_move(cube->posx, cube->posy - cube->diry))
		cube->posy -= MS * cube->diry;
	if (can_move(cube->posx - cube->dirx, cube->posy))
		cube->posx -= MS * cube->dirx;
}

void	move_left(t_cube *cube)
{
	if (can_move(cube->posx, cube->posy - cube->planey))
		cube->posy -= MS * cube->planey;
	if (can_move(cube->posx - cube->planex, cube->posy))
		cube->posx -= MS * cube->planex;
}

void	move_right(t_cube *cube)
{
	if (can_move(cube->posx, cube->posy + cube->planey))
		cube->posy += MS * cube->planey;
	if (can_move(cube->posx + cube->planex, cube->posy))
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
