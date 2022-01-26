/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:02:27 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:18:49 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = 0;
	if (!src && !dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (--dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
