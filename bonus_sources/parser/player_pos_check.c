/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 17:38:12 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	player_pos_check(char **map, t_params *params)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (params->player_sym != '0')
					ft_error("more than 1 player found\n");
				params->player_sym = map[i][j];
				params->player_x = j;
				params->player_y = i;
				map[i][j] = '0';
			}
		}		
	}
	if (params->player_x == -1 && params->player_y == -1)
		ft_error("player was not found\n");
	return (0);
}
