/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:35:36 by sinkosi           #+#    #+#             */
/*   Updated: 2019/05/30 14:48:39 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*control;

	i = 0;
	control = (char *)b;
	if (len == 0)
		return (control);
	while (i < len)
	{
		control[i] = c;
		i++;
	}
	return (control);
}
