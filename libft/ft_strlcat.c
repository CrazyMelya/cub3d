/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:33:18 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:18:59 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret_value;
	size_t	j;

	i = 0;
	ret_value = 0;
	j = 0;
	while (dst[i] && i < dstsize)
	{
		i++;
		ret_value++;
	}
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = ((char *)src)[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = 0;
	return (ft_strlen(src) + ret_value);
}
