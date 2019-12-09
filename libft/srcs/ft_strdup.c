/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:23:38 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/10 13:40:33 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if ((dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (ft_strcpy(dest, s1));
	return (NULL);
}
