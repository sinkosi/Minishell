/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:43:28 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/26 14:19:08 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_o_octal(t_printf *my_printf, uintmax_t n, int fd)
{
	char *str;

	str = ft_ltoa_base(n, 8);
	ft_tolower(my_printf->convert);
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
