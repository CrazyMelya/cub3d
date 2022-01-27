/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:23 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:24 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	move_forward(t_cube *cube)
{
	if (can_move(cube, cube->posx, cube->posy + cube->diry))
		cube->posy += MS * cube->diry;
	if (can_move(cube, cube->posx + cube->dirx, cube->posy))
		cube->posx += MS * cube->dirx;
}

void	move_backward(t_cube *cube)
{
	if (can_move(cube, cube->posx, cube->posy - cube->diry))
		cube->posy -= MS * cube->diry;
	if (can_move(cube, cube->posx - cube->dirx, cube->posy))
		cube->posx -= MS * cube->dirx;
}

void	move_left(t_cube *cube)
{
	if (can_move(cube, cube->posx, cube->posy - cube->planey))
		cube->posy -= MS * cube->planey;
	if (can_move(cube, cube->posx - cube->planex, cube->posy))
		cube->posx -= MS * cube->planex;
}

void	move_right(t_cube *cube)
{
	if (can_move(cube, cube->posx, cube->posy + cube->planey))
		cube->posy += MS * cube->planey;
	if (can_move(cube, cube->posx + cube->planex, cube->posy))
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
