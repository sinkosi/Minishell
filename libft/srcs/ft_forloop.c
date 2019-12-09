/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:15:59 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/22 11:44:50 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_forloop(int *begin, int condition, int step, void (*f)(int))
{
	int	i;

	i = 0;
	if (step == 0)
		return ;
	if (step > 0 && begin > condition)
		return ;
	if (step < 0 && begin < condition)
		return ;
	else
	{
		while (i < condition)
		{
			(*f)(begin[i]);
			i += step;
		}
	}
}
