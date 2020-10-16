/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:06:57 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/31 10:18:55 by kngalalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		i2;
	char	*str;
  int  len;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
  str = ((char *)malloc(sizeof(char) * len + 1));
	if (!str)
          return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		str[i + i2] = s2[i2];
		i2++;
	}
	str[i + i2] = '\0';
	return (str);
}
