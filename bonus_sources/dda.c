/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:01 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:03 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	ray_step(t_ray *ray)
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
}

void	dda(t_cube *cube, t_ray *ray)
{
	while (cube->map[ray->mapx][ray->mapy] != '1' && !ray->check)
	{
		if (ray->mapx > 0 && ray->mapx < cube->height && ray->mapy > 0 \
		&& ray->mapy < cube->width)
		{
			ray_step(ray);
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
