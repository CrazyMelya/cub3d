/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:07:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/26 20:59:19 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

int	closer(void)
{
	exit(0);
}

void	step_and_side(t_cube *cube, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (cube->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - cube->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (cube->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - cube->posy) * ray->deltadisty;
	}
}

int	draw(t_cube *cube)
{
	rot_mouse(cube);
	move(cube);
	cube->img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp, \
	&cube->img->line_length, &cube->img->endian);
	draw_terra_sky(cube);
	draw_walls(cube);
	draw_mini_map(cube);
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
		init_cube2(&cube, params);
		mlx_hook(cube.win, 17, 0, closer, NULL);
		mlx_hook(cube.win, 2, 0, key_press, &cube);
		mlx_hook(cube.win, 3, 0, key_release, &cube);
		mlx_mouse_hide();
		mlx_loop_hook(cube.mlx, draw, &cube);
		mlx_loop(cube.mlx);
	}
	else
		ft_error("correct usage: ./cub3D file_name.cub\n");
	return (0);
}
