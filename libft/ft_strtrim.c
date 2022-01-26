/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:35:42 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:16:20 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*new_str;
	size_t	rev_size;

	if (!str)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
		str++;
	rev_size = ft_strlen(str);
	while (ft_strchr(set, str[rev_size - 1]) && *str)
		rev_size--;
	new_str = ft_substr(str, 0, rev_size);
	return (new_str);
}
