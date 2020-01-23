/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:52:19 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/22 09:13:26 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char *i;

	i = 0;
	if (str != NULL)
		i = str;
	else if (i == NULL)
		return (NULL);
	str = i + ft_strspn(i, delim);
	i = str + ft_strcspn(str, delim);
	if (i == str)
	{
		i = 0;
		return (i);
	}
	(i = NULL);
	return (str);
}
/*
**char	*ft_strtok(char	*str, const char *delim)
**{
**	static char	*i = NULL;
**	char		*ptr;
**	int		n;
**
**	n = 0;
**	ptr = NULL;
**	if (str != NULL)
**		i = ft_strdup(str);
**	while (*i != '\0')
**	{
**		if (n == 0 && i != delim)
**		{
**			n = 1;
**			ptr = i;
**		}
**		else if (n == 1 && i == delim)
**		{
**			*i = '\0';
**			i += 1;
**			break;
**		}
**		i += 1;
**	}
**	return (ptr);
**}
*/
