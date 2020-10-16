/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:10:13 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/31 10:20:51 by kngalalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_cntwrd(char const *s, char c)
{
	int		i;
	int		cntr;

	i = 0;
	cntr = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			cntr++;
		}
		s++;
	}
	return (cntr);
}

static int			ft_lenw(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(const char *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	if (!s || !c)
		return (NULL);
	j = ft_cntwrd((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) * (ft_cntwrd((const char *)s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_lenw((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_lenw(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
