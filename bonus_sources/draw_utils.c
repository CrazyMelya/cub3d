/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:09 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:10 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

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

void	rot_mouse(t_cube *cube)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cube->win, &x, &y);
	if (x < WIDTH / 2)
		rot_left(cube);
	if (x > WIDTH / 2)
		rot_right(cube);
	mlx_mouse_move(cube->win, WIDTH / 2, HEIGHT / 2);
}
