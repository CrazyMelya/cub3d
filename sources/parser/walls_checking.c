/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:45 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	check(char **map_arr, t_params *params, int x, int y)
// {
// 	if (y == 0 || y == params->height - 1 || x == 0 || x == params->width - 1)
// 		ft_error("map not valid\n");
// 	else if(map_arr[y][x + 1] != '1' &&  map_arr[y][x + 1] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y][x - 1] != '1' &&  map_arr[y][x - 1] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y + 1][x] != '1' &&  map_arr[y + 1][x] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y - 1][x] != '1' &&  map_arr[y - 1][x] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y + 1][x + 1] != '1' &&  map_arr[y + 1][x + 1] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y + 1][x - 1] != '1' &&  map_arr[y + 1][x - 1] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y - 1][x - 1] != '1' &&  map_arr[y - 1][x - 1] != '0')
// 		ft_error("map not valid\n");
// 	else if(map_arr[y - 1][x + 1] != '1' &&  map_arr[y - 1][x + 1] != '0')
// 		ft_error("map not valid\n");
// }

void	check(char **map_arr, t_params *params, int x, int y)
{
	if ((y == 0 || y == params->height - 1 || x == 0 || x == params->width - 1)\
		|| (map_arr[y][x + 1] != '1' &&  map_arr[y][x + 1] != '0')\
		|| (map_arr[y][x - 1] != '1' &&  map_arr[y][x - 1] != '0')\
		|| (map_arr[y + 1][x] != '1' &&  map_arr[y + 1][x] != '0')\
		|| (map_arr[y - 1][x] != '1' &&  map_arr[y - 1][x] != '0')\
		|| (map_arr[y + 1][x + 1] != '1' &&  map_arr[y + 1][x + 1] != '0')\
		|| (map_arr[y + 1][x - 1] != '1' &&  map_arr[y + 1][x - 1] != '0')\
		|| (map_arr[y - 1][x - 1] != '1' &&  map_arr[y - 1][x - 1] != '0')\
		|| (map_arr[y - 1][x + 1] != '1' &&  map_arr[y - 1][x + 1] != '0'))
		ft_error("map not valid\n");
}

void	walls_checking(char **map_arr, t_params *params)
{
	int x;
	int y;

	y = 0;
	while(y < params->height)
	{
		x = 0;
		while (x < params->width)
		{
			if (map_arr[y][x] != '0' && map_arr[y][x] != '1' && map_arr[y][x] != 'X')
				ft_error("map not valid\n");
			if(map_arr[y][x] == '0')
				check(map_arr, params, x, y);
			x++;
		}
		y++;
	}
}

