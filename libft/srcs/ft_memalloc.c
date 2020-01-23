/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:59:49 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/12 11:31:39 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size < 0)
		return (NULL);
	s = (void *)malloc(sizeof(void) * (size));
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
