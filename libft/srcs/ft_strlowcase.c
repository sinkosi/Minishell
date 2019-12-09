/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:44:34 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 08:40:34 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]) == 1)
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
