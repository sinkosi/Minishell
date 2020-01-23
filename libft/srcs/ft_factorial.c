/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:42:31 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 13:43:05 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nbr)
{
	int i;

	i = nbr;
	if (nbr < 1)
		return (0);
	while (i > 0 && ft_isimax(nbr) == 0)
	{
		nbr *= i;
		i--;
	}
	if (ft_isimax(nbr) == 1)
		return (0);
	return (nbr);
}
