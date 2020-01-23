/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:43:21 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 13:43:36 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int pos;

	pos = 0;
	if (nb <= 1)
		return (0);
	while (pos == 0)
	{
		pos = ft_is_prime(nb);
		nb++;
	}
	return (nb);
}
