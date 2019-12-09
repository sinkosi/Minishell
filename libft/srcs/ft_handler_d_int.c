/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_d_int_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:15:18 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:15:44 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_handler_d_char(t_printf *my_printf, char c, int fd)
{
	ft_print_d_int(my_printf, c, fd);
}

static void	ft_handler_d_short(t_printf *my_printf, short n, int fd)
{
	ft_print_d_int(my_printf, n, fd);
}

void		ft_handler_d_int(t_printf *my_printf,
		va_list printf_list, int fd)
{
	ft_flag_check(my_printf);
	if (my_printf->h == 1)
		ft_handler_d_short(my_printf, va_arg(printf_list, int), fd);
	else if (my_printf->h == 2)
		ft_handler_d_char(my_printf, va_arg(printf_list, int), fd);
	else if (my_printf->l == 1)
		ft_print_d_int(my_printf, va_arg(printf_list, long), fd);
	else if (my_printf->l == 2)
		ft_print_d_int(my_printf, va_arg(printf_list, long long), fd);
	else if (my_printf->j == 1)
		ft_print_d_int(my_printf, va_arg(printf_list, intmax_t), fd);
	else if (my_printf->z == 1)
		ft_print_d_int(my_printf, va_arg(printf_list, size_t), fd);
	else
		ft_print_d_int(my_printf, va_arg(printf_list, int), fd);
}
