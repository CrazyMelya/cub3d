/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:12:59 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:17 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_filing(char *map, char **map_arr, int w, int h)
{
	int	i;
	int	j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (*map != '\n' && *map != '\0')
		{
			if (*map == ' ')
				map_arr[i][++j] = 'X';
			else
				map_arr[i][++j] = *map;
			map++;
		}
		if (*map == '\n' || *map == '\0')
		{
			while (++j < w)
				map_arr[i][j] = 'X';
		}
		if (*map == '\0')
			break ;
		map++;
	}
}