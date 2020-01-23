/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:51:43 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/21 14:40:16 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (len == 0)
		return (s1);
	if (s1 == '\0' && s2 == '\0')
		return (0);
	if (s1 > s2)
	{
		while (len != '\0')
		{
			len--;
			s1[len] = s2[len];
		}
	}
	else
		s1 = ft_memcpy(dst, src, len);
	return (s1);
}
