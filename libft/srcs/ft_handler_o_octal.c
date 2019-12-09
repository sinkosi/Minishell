/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_o_octal_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:14:15 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:14:38 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_handler_o_short(t_printf *my_printf, unsigned short n, int fd)
{
	ft_print_o_octal(my_printf, n, fd);
}

static void	ft_handler_o_char(t_printf *my_printf, unsigned char c, int fd)
{
	ft_print_o_octal(my_printf, c, fd);
}

void		ft_handler_o_octal(t_printf *my_printf,
		va_list printf_list, int fd)
{
	ft_flag_check(my_printf);
	if (my_printf->h == 1)
		ft_handler_o_short(my_printf, va_arg(printf_list, unsigned int), fd);
	else if (my_printf->h == 2)
		ft_handler_o_char(my_printf, va_arg(printf_list, unsigned int), fd);
	else if (my_printf->l == 1)
		ft_print_o_octal(my_printf, va_arg(printf_list, unsigned long), fd);
	else if (my_printf->l == 2)
		ft_print_o_octal(my_printf,
				va_arg(printf_list, unsigned long long), fd);
	else if (my_printf->j == 1)
		ft_print_o_octal(my_printf, va_arg(printf_list, uintmax_t), fd);
	else if (my_printf->z == 1)
		ft_print_o_octal(my_printf, va_arg(printf_list, size_t), fd);
	else
		ft_print_o_octal(my_printf, va_arg(printf_list, unsigned int), fd);
}
