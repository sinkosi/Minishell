/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:51:12 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/21 16:56:01 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_uppercase(char *str)
{
	size_t	i;
	int		control;

	if (str == NULL)
		return (1);
	control = 1;
	i = 0;
	while (str[i] != '\0' && control == 1)
	{
		control = (ft_isupper(str[i]));
		i++;
	}
	return (control);
}
