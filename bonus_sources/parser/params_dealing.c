/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_dealing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 17:40:38 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_texture(char **params_line, char **params_name)
{
	if (*params_name != NULL)
		ft_error("params duplicates in .cub found\n");
	if (arr_len(params_line) != 2)
		ft_error("wrong number of args in params\n");
	*params_name = ft_strdup(params_line[1]);
}

int	check_colors(char **params_line, int *params_val)
{
	char	**colors;
	int		i;

	i = 0;
	if (arr_len(params_line) != 2)
		ft_error("wrong number of args in params\n");
	if (params_val[0] != -1)
		ft_error("params duplicates in .cub found\n");
	colors = ft_split(params_line[1], ',');
	if (colors == NULL)
		ft_error("string splitting error\n");
	if (arr_len(colors) != 3)
		ft_error("rgb is incorrect\n");
	while (i < 3)
	{
		if (!is_digitstr(colors[i]))
			ft_error("rgb is incorrect\n");
		params_val[i] = ft_atoi(colors[i]);
		if (params_val[i] < 0 || params_val[i] > 255)
			ft_error("rgb is incorrect\n");
		i++;
	}
	arr_free(colors);
	return (0);
}

void	text_color_check(t_params *params, char **param_split)
{
	if (ft_strncmp(param_split[0], "NO", 3) == 0)
		check_texture(param_split, &params->no);
	else if (ft_strncmp(param_split[0], "SO", 3) == 0)
		check_texture(param_split, &params->so);
	else if (ft_strncmp(param_split[0], "WE", 3) == 0)
		check_texture(param_split, &params->we);
	else if (ft_strncmp(param_split[0], "EA", 3) == 0)
		check_texture(param_split, &params->ea);
	else if (ft_strncmp(param_split[0], "F", 2) == 0)
		check_colors(param_split, params->floor);
	else if (ft_strncmp(param_split[0], "C", 2) == 0)
		check_colors(param_split, params->ceiling);
	else
		ft_error("invalid line\n");
}

int	params_dealing(char *line, t_params *params, int *num)
{
	char	**split_params;

	if (ft_strlen(line) == 0 || ft_strchr2(line, " \0"))
		return (0);
	split_params = ft_split(line, ' ');
	if (split_params == NULL)
		ft_error("string splitting error\n");
	text_color_check(params, split_params);
	arr_free(split_params);
	(*num)++;
	return (0);
}
