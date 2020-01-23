/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:46:24 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/28 09:46:25 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flag_plus(t_printf *my_printf, int fd)
{
	if (my_printf->flag_plus == -1)
	{
		ft_putchar_fd('-', fd);
		my_printf->f_return += 1;
	}
	else if (my_printf->flag_plus == 1)
	{
		ft_putchar_fd('+', fd);
		my_printf->f_return += 1;
	}
	if (my_printf->flag_zero == 1 && my_printf->flag_plus != 0)
		my_printf->flag_plus = 2;
}
