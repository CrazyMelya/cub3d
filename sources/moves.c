/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:34:05 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:58:34 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int key, t_cube *cube)
{
	if (key == 53)
		closer();
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
