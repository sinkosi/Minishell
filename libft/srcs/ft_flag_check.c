/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:42:53 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/07 08:40:45 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_flag_set_zero(t_printf *my_printf)
{
	my_printf->h = 0;
	my_printf->l = 0;
	my_printf->j = 0;
	my_printf->z = 0;
}

void		ft_flag_check(t_printf *my_printf)
{
	if ((my_printf->h > 0) && (my_printf->l > 0 || my_printf->j > 0
			|| my_printf->z > 0))
	{
		ft_flag_set_zero(my_printf);
		my_printf->j = 1;
	}
	else if ((my_printf->l > 0) && (my_printf->h > 0 || my_printf->j > 0
			|| my_printf->z > 0))
	{
		ft_flag_set_zero(my_printf);
		my_printf->j = 1;
	}
	else if ((my_printf->j > 0) && (my_printf->l > 0 || my_printf->h > 0
			|| my_printf->z > 0))
	{
		ft_flag_set_zero(my_printf);
		my_printf->j = 1;
	}
	else if ((my_printf->z > 0) && (my_printf->h > 0 || my_printf->l > 0
			|| my_printf->j > 0))
	{
		ft_flag_set_zero(my_printf);
		my_printf->j = 1;
	}
}
