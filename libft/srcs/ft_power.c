/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:44:39 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 13:44:54 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_power(intmax_t nb, int power)
{
	intmax_t my_power;

	my_power = nb;
	if (power < 0)
		return (-1);
	else if (power == 0)
		return (1);
	while (power > 1 && (ft_isimax(nb) == 0))
	{
		my_power *= nb;
		power--;
	}
	return (my_power);
}
