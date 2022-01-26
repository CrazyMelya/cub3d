/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:19:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 18:08:06 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr2(char *str, char *search)
{
	while (*str)
	{
		if (ft_strchr(search, *str) == NULL)
			return (0);
		str++;
	}
	return (1);
}
