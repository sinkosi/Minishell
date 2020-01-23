/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_bool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:10:47 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 11:11:56 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_round_bool(double nbr)
{
	intmax_t	num;

	num = nbr;
	nbr -= num;
	if (nbr >= 0.5)
		return (1);
	else
		return (0);
}
