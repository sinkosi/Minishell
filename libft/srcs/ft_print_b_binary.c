/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 09:47:04 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:24:13 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_b_binary(t_printf *my_printf, uintmax_t n, int fd)
{
	char *str;

	str = ft_ltoa_base(n, 2);
	ft_flag_size(my_printf, ft_strlen(str));
	ft_flag_width(my_printf, fd);
	ft_flag_precision(my_printf, str, fd);
	my_printf->f_return += ft_strlen(str);
	ft_putstr_fd(str, fd);
	if (my_printf->flag_minus == 2 && my_printf->prec_width == 0)
		my_printf->field_width -= 1;
	ft_flag_width(my_printf, fd);
	ft_strdel(&str);
}
