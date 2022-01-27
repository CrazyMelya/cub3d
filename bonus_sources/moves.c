/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:20 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:22 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

int	can_move(t_cube *cube, int x, int y)
{
	if (cube->map[x][y] == '0' || cube->map[x][y] == '2')
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
