#include "../include/cub3d.h"

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

