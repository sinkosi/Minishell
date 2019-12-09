/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:47:04 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:15:03 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_handler_s_str(t_printf *my_printf, va_list printf_list, int fd)
{
	ft_flag_check(my_printf);
	if (my_printf->l != 1 && my_printf->convert == 's')
		ft_print_s_str(my_printf, va_arg(printf_list, char *), fd);
	else if (my_printf->convert == 'S')
		ft_print_ws_str(my_printf, va_arg(printf_list, wchar_t *), fd);
}
