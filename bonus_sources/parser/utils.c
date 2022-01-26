/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:31 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	arr_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

char	**arr_create(t_params *elem)
{
	char	**arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char *) * (elem->height + 1));
	if (arr == NULL)
		ft_error("malloc error\n");
	while (i < elem->height)
	{
		arr[i] = malloc(elem->width + 1);
		if (arr[i] == NULL)
			ft_error("malloc error\n");
		arr[i][elem->width] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	is_digitstr(char *str)
{
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}
