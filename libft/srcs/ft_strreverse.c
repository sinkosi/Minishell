/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:19:23 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/12 14:19:49 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *s)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = ft_strlen(s);
	a = ft_strnew(i + 1);
	j = 0;
	while (j < ft_strlen(s))
	{
		a[j] = s[i - 1];
		j++;
		i--;
	}
	a[j] = '\0';
	return (a);
}
