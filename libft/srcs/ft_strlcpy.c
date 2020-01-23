/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:44:54 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/22 09:06:40 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (src == NULL)
		return (0);
	i = ft_strlen(src);
	j = 0;
	if (i == 0)
	{
		dst[i] = '\0';
		return (i);
	}
	if (dstsize == 0)
		return (i);
	while (j < (dstsize - 1) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	if (dstsize < i)
		return (ft_strlen(src));
	return (j);
}
