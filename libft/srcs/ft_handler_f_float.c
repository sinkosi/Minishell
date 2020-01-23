/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_f_float_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:12:22 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/11 13:51:26 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_handler_f_float(t_printf *my_printf,
		va_list printf_list, int fd)
{
	ft_flag_check(my_printf);
	if (my_printf->l == 1)
		ft_print_f_float(my_printf, va_arg(printf_list, double), fd);
	else if (my_printf->l == 2)
		ft_print_f_float(my_printf, va_arg(printf_list, double), fd);
	else if (my_printf->lc == 1)
		ft_print_f_float(my_printf, va_arg(printf_list, long double), fd);
	else if (my_printf->j == 1)
		ft_print_f_float(my_printf, va_arg(printf_list, intmax_t), fd);
	else if (my_printf->z == 1)
		ft_print_f_float(my_printf, va_arg(printf_list, size_t), fd);
	else
		ft_print_f_float(my_printf, va_arg(printf_list, double), fd);
}
