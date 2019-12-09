/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:15:09 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/10 10:45:53 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*str1;
	char			*str2;
	size_t			i;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (i > n)
		return (0);
	while (i < n)
	{
		str1[i] = str2[i];
		if ((unsigned char)str1[i] == (unsigned char)c)
			return ((char *)str1 + i + 1);
		i++;
	}
	return (NULL);
}
