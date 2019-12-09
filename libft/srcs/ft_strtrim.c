/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:14:31 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/14 15:37:25 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char const *c)
{
	size_t	i;

	i = 0;
	while ((c[i] == ' ' || c[i] == '\n' || c[i] == '\t') && c[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_rcheck(char const *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(c) - 1;
	while ((c[j] == ' ' || c[j] == '\n' || c[j] == '\t') && j >= 0)
	{
		j--;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	k = 0;
	j = ft_check(s);
	if (j == i)
	{
		return ("");
	}
	k = ft_rcheck(s);
	str = ft_strnew(i - j - k);
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, j, (i - j - k));
	return (str);
}
