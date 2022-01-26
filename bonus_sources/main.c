/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:07:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/26 20:25:13 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

int	closer(void)
{
	exit(0);
}

void	draw_mini_map(t_cube *cube)
{
	t_mini_map map;

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
			map.y += map.stepy;
			map.mini_y++;
		}
		map.x += map.stepx;
		map.mini_x++;
	}
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

void	init_ray(t_cube *cube, t_ray *ray, int x)
{
	ray->camerax = (2 * x / (double) WIDTH) - 1;
	ray->raydirx = cube->dirx + cube->planex * ray->camerax;
	ray->raydiry = cube->diry + cube->planey * ray->camerax;
	ray->mapx = (int)cube->posx;
	ray->mapy = (int)cube->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
	ray->check = 0;
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

void	dda(t_cube *cube, t_ray *ray)
{
	while (cube->map[ray->mapx][ray->mapy] != '1' && !ray->check)
	{
		if (ray->mapx > 0 && ray->mapx < cube->height && ray->mapy > 0 && ray->mapy < cube->width)
		{
			if (ray->sidedistx < ray->sidedisty)
			{
				ray->sidedistx += ray->deltadistx;
				ray->mapx += ray->stepx;
				ray->side = 0;
			}
			else
			{
				ray->sidedisty += ray->deltadisty;
				ray->mapy += ray->stepy;
				ray->side = 1;
			}
			if (cube->map[ray->mapx][ray->mapy] == '2')
				add_door_front(&cube->doors, new_door(cube, ray, 2));
			else if (cube->map[ray->mapx][ray->mapy] == '3')
				add_door_front(&cube->doors, new_door(cube, ray, 3));
		}
		else
			ray->check = 1;
	}
	if (ray->side)
		ray->perpwalldist = ray->sidedisty - ray->deltadisty;
	else
		ray->perpwalldist = ray->sidedistx - ray->deltadistx;
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
}

void	tex_pos_init(t_cube *cube, t_ray *ray)
{
	double	wallx;

	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
	if (ray->side)
		wallx = cube->posx + ray->perpwalldist * ray->raydirx;
	else
		wallx = cube->posy + ray->perpwalldist * ray->raydiry;
	wallx -= floor(wallx);
	ray->texx = (int)(wallx * (double)TEX);
	if (!ray->side && ray->raydirx > 0)
		ray->texx = TEX - ray->texx;
	if (ray->side && ray->raydiry < 0)
		ray->texx = TEX - ray->texx;
	ray->step = (double) TEX / ray->lineheight;
	ray->texpos = ray->drawstart - HEIGHT / 2 + ray->lineheight / 2;
	ray->texpos *= ray->step;
}

void	texturing(t_cube *cube, t_ray *ray, int x)
{
	int	color;
	int	y;

	y = ray->drawstart;
	while (y < ray->drawend)
	{
		ray->texy = (int)ray->texpos;
		ray->texpos += ray->step;
		if (ray->side)
		{
			if (ray->stepy == 1)
				color = get_color(&cube->tex[2], ray->texx, ray->texy);
			else
				color = get_color(&cube->tex[3], ray->texx, ray->texy);
		}
		else
		{
			if (ray->stepx == 1)
				color = get_color(&cube->tex[0], ray->texx, ray->texy);
			else
				color = get_color(&cube->tex[1], ray->texx, ray->texy);
		}
		apply_pixel(cube->img, x, y, color);
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
		dda(cube, &ray);
		if (!ray.check)
		{
			tex_pos_init(cube, &ray);
			texturing(cube, &ray, x);
			draw_doors(cube, cube->doors, x);
		}
		free_doors(&cube->doors);
		x++;
	}
}

void rot_mouse(t_cube *cube)
{
	int x;
	int	y;

	mlx_mouse_get_pos(cube->win, &x, &y);
	if (x < WIDTH / 2)
		rot_left(cube);
	if (x > WIDTH / 2)
		rot_right(cube);
	mlx_mouse_move(cube->win, WIDTH / 2, HEIGHT / 2);
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
