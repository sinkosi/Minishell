/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:55:29 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/21 11:46:17 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numwrds(char const *s, char c)
{
	size_t		i;
	size_t		control;

	i = 0;
	control = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			control++;
		}
	}
	return (control);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**ptopntr;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if (!(ptopntr = (char **)malloc(sizeof(char *) * (ft_numwrds(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			ptopntr[k++] = ft_strsub(s, j, i - j);
		}
	}
	ptopntr[k] = NULL;
	return (ptopntr);
}
