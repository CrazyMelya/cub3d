/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:33:57 by cliza             #+#    #+#             */
/*   Updated: 2022/01/26 20:20:06 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	init_texture(t_cube *cube, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cube->mlx, path, &tex->x, &tex->y);
	if (!tex->img)
		ft_error("wrong image\n");
	if (tex->x < TEX || tex->y < TEX)
		ft_error("wrong image size\n");	
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, \
	&tex->size_line, &tex->endian);
}

void	init_plane(t_cube *cube, t_params *params)
{
	if (params->player_sym == 'N')
	{
		cube->planex = 0;
		cube->planey = 0.66;
	}
	if (params->player_sym == 'S')
	{
		cube->planex = 0;
		cube->planey = -0.66;
	}
	if (params->player_sym == 'W')
	{
		cube->planex = -0.66;
		cube->planey = 0;
	}
	if (params->player_sym == 'E')
	{
		cube->planex = 0.66;
		cube->planey = 0;
	}
}

void	init_dir(t_cube *cube, t_params *params)
{
	if (params->player_sym == 'N')
	{
		cube->dirx = -1;
		cube->diry = 0;
	}
	if (params->player_sym == 'S')
	{
		cube->dirx = 1;
		cube->diry = 0;
	}
	if (params->player_sym == 'W')
	{
		cube->dirx = 0;
		cube->diry = -1;
	}
	if (params->player_sym == 'E')
	{
		cube->dirx = 0;
		cube->diry = 1;
	}
}

void	shifting_colors(t_cube *cube, t_params *params)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		cube->floor[i] = params->floor[i];
		cube->ceiling[i] = params->ceiling[i];
		i++;
	}
}

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
