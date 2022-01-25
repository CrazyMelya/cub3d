/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:07:06 by cliza             #+#    #+#             */
/*   Updated: 2022/01/25 11:17:40 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

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
		{1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,3,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

int	closer(void)
{
	exit(0);
}

void	draw_mini_map(t_cube *cube)
{
	mini_map map;

	map.mini_x = WIDTH / 100;
	map.stepx = 30 * cube->map_scale;
	map.stepy = 24 * cube->map_scale;
	map.x = 0;
	while (map.x < 30)
	{
		map.y = 0;
		map.mini_y = HEIGHT / 100;
		while (map.y < 24)
		{
			if (worldMap[(int)map.x][(int)map.y] == 1)
				apply_pixel(cube->img, map.mini_y, map.mini_x, 0xffffff);
			if (worldMap[(int)map.x][(int)map.y] == 2)
				apply_pixel(cube->img, map.mini_y, map.mini_x, 0x0000ff);
			if (worldMap[(int)map.x][(int)map.y] == 3)
				apply_pixel(cube->img, map.mini_y, map.mini_x, 0xff0000);
			if (worldMap[(int)map.x][(int)map.y] == 0)
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
				color = 0x645ac8;
			else
				color = 0x0110f;
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
	while (worldMap[ray->mapx][ray->mapy] != 1 && !ray->check)
	{
		if (ray->mapx > 0 && ray->mapx < 30 && ray->mapy > 0 && ray->mapy < 24)
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
			if (worldMap[ray->mapx][ray->mapy] == 2)
				add_door_front(&cube->doors, new_door(cube, ray, 2));
			else if (worldMap[ray->mapx][ray->mapy] == 3)
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
				color = get_color(&cube->tex[4], ray->texx, ray->texy);
			else
				color = get_color(&cube->tex[4], ray->texx, ray->texy);
		}
		else
		{
			if (ray->stepx == 1)
				color = get_color(&cube->tex[4], ray->texx, ray->texy);
			else
				color = get_color(&cube->tex[4], ray->texx, ray->texy);
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
	cube->tex = malloc(sizeof(t_texture) * 8);
	cube->map_scale = 0.01;
	cube->doors = NULL;
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
	init_texture(cube, &cube->tex[4], "texs/mettal1.xpm");
	init_texture(cube, &cube->tex[5], "texs/portal_blue_mettal1.xpm");
	init_texture(cube, &cube->tex[6], "texs/portal_orange_mettal1.xpm");
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
}
