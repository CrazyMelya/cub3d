/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:11 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:13 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	init_cube(t_cube *cube, t_params *params)
{
	cube->key = malloc(sizeof(t_keys));
	cube->img = malloc(sizeof(t_img));
	cube->tex = malloc(sizeof(t_texture) * 6);
	cube->doors = NULL;
	cube->key->a = 0;
	cube->key->s = 0;
	cube->key->w = 0;
	cube->key->d = 0;
	cube->key->left = 0;
	cube->key->right = 0;
	cube->key->esc = 0;
	cube->map_scale = 0.01;
	cube->posx = params->player_y + 0.1;
	cube->posy = params->player_x + 0.1;
	shifting_colors(cube, params);
}

void	init_cube2(t_cube *cube, t_params *params)
{
	cube->width = params->width;
	cube->height = params->height;
	cube->map = params->map;
	init_dir(cube, params);
	init_plane(cube, params);
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cube3d");
	init_texture(cube, &cube->tex[0], params->no);
	init_texture(cube, &cube->tex[1], params->so);
	init_texture(cube, &cube->tex[2], params->we);
	init_texture(cube, &cube->tex[3], params->ea);
	init_texture(cube, &cube->tex[4], "texs/blue_portal.xpm");
	init_texture(cube, &cube->tex[5], "texs/orange_portal.xpm");
}
