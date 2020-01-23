/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:43:58 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 08:42:48 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_islower(str[i]) == 1)
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
