/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:35:11 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:17:33 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p_str;

	p_str = (char *)str;
	i = 0;
	while (p_str[i])
		i++;
	while (i >= 0)
	{
		if (p_str[i] == c)
			return (&p_str[i]);
		i--;
	}
	return ((char *) NULL);
}
