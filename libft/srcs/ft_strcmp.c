/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:11:22 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/10 09:15:40 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(s2) != 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else if (ft_strlen(s1) != 0 && ft_strlen(s2) == 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
