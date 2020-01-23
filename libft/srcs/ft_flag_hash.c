/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:44:31 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:23:41 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flag_hash(t_printf *my_printf, char *str, int fd)
{
	if (my_printf->convert == 'o' && str[0] != '0' && my_printf->flag_hash == 1)
	{
		ft_putchar_fd('0', fd);
		my_printf->f_return++;
	}
	else if (my_printf->convert == 'x' && str[0] != '0' &&
			my_printf->flag_hash == 1)
	{
		ft_putstr_fd("0x", fd);
		my_printf->f_return += 2;
	}
	else if (my_printf->convert == 'X' && str[0] != '0' &&
			my_printf->flag_hash == 1)
	{
		ft_putstr_fd("0X", fd);
		my_printf->f_return += 2;
	}
	my_printf->i += 1;
}
