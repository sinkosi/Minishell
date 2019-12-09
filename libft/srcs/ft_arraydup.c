/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:59:21 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 08:10:07 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(const char **arr)
{
	int		n;
	int		i;
	char	**new;

	i = 0;
	n = 0;
	while (arr[n] != NULL)
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		return (NULL);
	while (arr[n] != NULL)
	{
		new[n] = ft_strdup(arr[n]);
		n++;
	}
	new[n] = NULL;
	return (new);
}
