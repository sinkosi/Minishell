/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:40:52 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/30 12:41:05 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t	ft_power_ten(double nb, int power)
{
	intmax_t	ten;
	int			i;

	ten = 10;
	i = 0;
	if (power < 0)
		return (-1);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		ten *= 10;
		power--;
		if (power == 1)
			i = ft_round_bool(nb * ten);
	}
	return ((nb * ten) + i);
}
