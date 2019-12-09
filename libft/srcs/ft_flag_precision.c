/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:04:16 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:55:40 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The purpose of this function is to be
*/

void	ft_flag_precision(t_printf *my_printf, char *str, int fd)
{
	char	c;

	c = my_printf->convert;
	if ((str[0] != '0') && (my_printf->prec_width < 0) &&
			(my_printf->flag_hash == 1) && ((c == 'o') || (c == 'O')))
	{
		ft_putchar_fd('0', fd);
		my_printf->f_return += 1;
	}
	if (c == 'i' || c == 'd' || c == 'x' || c == 'X' || c == 'o' ||
			c == 'p' || c == 'u' || c == 'U')
		while (my_printf->prec_width > 0)
		{
			ft_putchar_fd('0', fd);
			my_printf->prec_width -= 1;
			my_printf->f_return += 1;
		}
}
