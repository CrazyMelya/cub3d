/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:27:13 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 12:21:00 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t i)
{
	char	*temp;

	temp = (char *)b;
	while (i > 0)
	{
		*temp = c;
		temp++;
		i--;
	}
	return (b);
}
