/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:07 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	check_cubemap(t_mini_map map, t_cube *cube)
{
	if (cube->map[(int)map.x][(int)map.y] == '1')
		apply_pixel(cube->img, map.mini_y, map.mini_x, 0xffffff);
	if (cube->map[(int)map.x][(int)map.y] == '2')
		apply_pixel(cube->img, map.mini_y, map.mini_x, 0x0000ff);
	if (cube->map[(int)map.x][(int)map.y] == '3')
		apply_pixel(cube->img, map.mini_y, map.mini_x, 0xff0000);
	if (cube->map[(int)map.x][(int)map.y] == '0')
		apply_pixel(cube->img, map.mini_y, map.mini_x, 0x000000);
	if ((int)map.x == (int)cube->posx && (int)map.y == (int)cube->posy)
		apply_pixel(cube->img, map.mini_y, map.mini_x, 0x00ff00);
}

void	draw_mini_map(t_cube *cube)
{
	t_mini_map	map;

	map.mini_x = WIDTH / 100;
	map.stepx = cube->height * cube->map_scale;
	map.stepy = cube->width * cube->map_scale;
	map.x = 0;
	while (map.x < cube->height)
	{
		map.y = 0;
		map.mini_y = HEIGHT / 100;
		while (map.y < cube->width)
		{
			check_cubemap(map, cube);
			map.y += map.stepy;
			map.mini_y++;
		}
		map.x += map.stepx;
		map.mini_x++;
	}
}
