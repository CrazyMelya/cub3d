/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:29:28 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:21:36 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t i)
{
	int	a;

	a = (int)i;
	while (i > 0)
	{
		if (*(const unsigned char *)dst == (unsigned char)c)
			return ((char *)dst);
		dst++;
		i--;
	}
	return (NULL);
}
