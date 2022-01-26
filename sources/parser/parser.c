/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:25 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_params(t_params *params)
{
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->floor[0] = -1;
	params->floor[1] = -1;
	params->floor[2] = -1;
	params->ceiling[0] = -1;
	params->ceiling[1] = -1;
	params->ceiling[2] = -1;
	params->width = 0;
	params->height = 0;
	params->player_sym = '0';
	params->player_x = -1;
	params->player_y = -1;
}

int	define_map_size(char *line, t_params *params)
{
	int	len;
	int	i;

	i = 0;
	params->width = 0;
	params->height = 0;
	while (line[i] != '\0')
	{
		len = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			i++;
			len++;
		}
		if (len > params->width)
			params->width = len;
		if (line[i] == '\n')
			i++;
		params->height++;
	}
	return (0);
}

t_params	*parser(char **argv)
{
	t_params	*params;
	char		*map_str;
	int fd;

	if(!(params = malloc(sizeof(t_params))))
		ft_error("malloc error\n");
	init_params(params);
	map_str = NULL;
	fd = open(argv[1], O_RDONLY, 0);
	map_str = map_reading(fd, params, &map_str);
	if (map_str == NULL)
		ft_error("Map not found\n");
	define_map_size(map_str, params);
	params->map = arr_create(params);
	map_filing(map_str, params->map, params->width, params->height);
	player_pos_check(params->map, params);
	walls_checking(params->map, params);
	free(map_str);
	close(fd);
	return (params);
}


