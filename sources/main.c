/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:07:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/25 15:13:44 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[30][24]= 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

int	closer(void)
{
	exit(0);
}

void	draw_terra_sky(t_cube *cube)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				color = 0x645ac8;
			else
				color = 0x0110f;
			apply_pixel(cube->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(cube, &ray, x);
		step_and_side(cube, &ray);
		dda(&ray);
		if (!ray.check)
		{
			tex_pos_init(cube, &ray);
			texturing(cube, &ray, x);
		}
		x++;
	}
}

int	draw(t_cube *cube)
{
	move(cube);
	cube->img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp, \
	&cube->img->line_length, &cube->img->endian);
	draw_terra_sky(cube);
	draw_walls(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img);
	return (0);
}

void	init_texture(t_cube *cube, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cube->mlx, path, &tex->x, &tex->y);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, \
	&tex->size_line, &tex->endian);
}

void	init_cube(t_cube *cube)
{
	cube->key = malloc(sizeof(t_keys));
	cube->img = malloc(sizeof(t_img));
	cube->tex = malloc(sizeof(t_texture) * 4);
	cube->key->a = 0;
	cube->key->s = 0;
	cube->key->w = 0;
	cube->key->d = 0;
	cube->key->left = 0;
	cube->key->right = 0;
	cube->key->esc = 0;
	cube->posx = 15.1;
	cube->posy = 15.1;
	cube->dirx = 0;
	cube->diry = -1;
	cube->planex = -0.66;
	cube->planey = 0;
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cube3d");
	init_texture(cube, &cube->tex[0], "texs/spider-man.xpm");
	init_texture(cube, &cube->tex[1], "texs/spawn.xpm");
	init_texture(cube, &cube->tex[2], "texs/batman.xpm");
	init_texture(cube, &cube->tex[3], "texs/deadpool.xpm");
}

int	main(void)
{
	t_cube	cube;

	init_cube(&cube);
	mlx_hook(cube.win, 17, 0, closer, NULL);
	mlx_hook(cube.win, 2, 0, key_press, &cube);
	mlx_hook(cube.win, 3, 0, key_release, &cube);
	mlx_mouse_hide();
	mlx_loop_hook(cube.mlx, draw, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
