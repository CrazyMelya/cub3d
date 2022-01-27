/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:07:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:56:15 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				color = (cube->ceiling[0] << 16) | (cube->ceiling[1] << 8) \
				| cube->ceiling[2];
			else
				color = (cube->floor[0] << 16) | (cube->floor[1] << 8) \
				| cube->floor[2];
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
	if (cube->posx > 0 && cube->posx < cube->height && cube->posy > 0 \
		&& cube->posy < cube->width)
	{
		while (x < WIDTH)
		{
			init_ray(cube, &ray, x);
			step_and_side(cube, &ray);
			dda(cube, &ray);
			tex_pos_init(cube, &ray);
			texturing(cube, &ray, x);
			x++;
		}
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

int	main(int argc, char **argv)
{
	t_cube		cube;
	t_params	*params;
	int			file;

	if (argc == 2)
	{
		file = file_checking(argv[1]);
		if (file != 0)
			ft_error("file opening problem\n");
		params = parser(argv);
		init_cube(&cube, params);
		mlx_hook(cube.win, 17, 0, closer, NULL);
		mlx_hook(cube.win, 2, 0, key_press, &cube);
		mlx_hook(cube.win, 3, 0, key_release, &cube);
		mlx_loop_hook(cube.mlx, draw, &cube);
		mlx_loop(cube.mlx);
	}
	else
		ft_error("correct usage: ./cub3D file_name.cub\n");
	return (0);
}
