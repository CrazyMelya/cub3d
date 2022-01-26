/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 20:01:34 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	record_map(int num, int empty_line, char *line, char **map)
{
	char	*old_map;

	if (num < 6)
		ft_error("map should be after params\n");
	if (empty_line)
		ft_error("empty lines in map content\n");
	if (*map == NULL)
	{
		*map = ft_strdup(line);
		if (*map == NULL)
			ft_error("no content in map\n");
		return (0);
	}
	old_map = ft_strjoin(*map, "\n");
	if (old_map == NULL)
		ft_error("no content in map\n");
	free(*map);
	*map = ft_strjoin(old_map, line);
	if (*map == NULL)
		ft_error("no content in map\n");
	free(old_map);
	old_map = NULL;
	return (1);
}

char	*map_reading(int fd, t_params *params, char **map)
{
	char	*line;
	int		num;
	int		gnl;
	int		empty_line;

	empty_line = 0;
	num = 0;
	gnl = 1;
	line = NULL;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (!ft_strchr2(line, "0123WENS ") || !ft_strlen(line) \
		|| ft_strchr2(line, " "))
		{
			params_dealing(line, params, &num);
			if (*map != NULL)
				empty_line += 1;
		}
		else if (ft_strchr2(line, "0123WENS "))
			record_map(num, empty_line, line, map);
		free(line);
	}
	return (*map);
}
