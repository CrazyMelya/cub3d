/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:33:57 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:18 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

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
