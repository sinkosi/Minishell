/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:48:41 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 09:50:42 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	int		space;
	int		cas;

	i = 0;
	space = 1;
	cas = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0)
			space = 1;
		else if (ft_isalnum(str[i]) == 1 && space == 1)
		{
			str[i] = ft_toupper(str[i]);
			space = 0;
			cas = 1;
		}
		else if (ft_isalnum(str[i]) == 1 && cas == 1)
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
