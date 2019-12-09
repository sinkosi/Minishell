/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 07:40:14 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 07:40:27 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_alnum(char *str)
{
	size_t	i;
	int		control;

	if (str == NULL)
		return (1);
	control = 1;
	i = 0;
	while (str[i] != '\0' && control == 1)
	{
		control = (ft_isalnum(str[i]));
		i++;
	}
	return (control);
}
