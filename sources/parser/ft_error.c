/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:14 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_error(char *str)
{
    ft_putstr_fd(STDERR_FILENO,"Error:\n");
	ft_putstr_fd(STDERR_FILENO, str);
	exit(1);
}
