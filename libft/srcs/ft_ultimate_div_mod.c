/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 08:17:42 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 08:18:23 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ultimate_div_mod(int *a, int *b)
{
	int *temp_a;
	int *temp_b;

	temp_a = a;
	temp_b = b;
	*a = *temp_a / *temp_b;
	*b = *temp_a % *temp_b;
}
