#include "../include/cub3d.h"

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

