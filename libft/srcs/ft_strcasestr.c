/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:45:55 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 07:46:52 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	s = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (s);
	while (s[i] != '\0')
	{
		j = 0;
		while (ft_tolower(s[i + j]) == ft_tolower(needle[j]))
		{
			if (needle[j + 1] == '\0')
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
