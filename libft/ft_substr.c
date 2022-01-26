/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:35:58 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:16:05 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = NULL;
	if (!s)
		return (NULL);
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == 0)
		return (NULL);
	if (ft_strlen(s) >= start)
		ft_strlcpy(dest, &s[start], len + 1);
	return (dest);
}
