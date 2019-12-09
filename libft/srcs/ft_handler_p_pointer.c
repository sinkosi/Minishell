/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:45:08 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:49:56 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_handler_p_pointer(t_printf *my_printf, va_list printf_list,
		int fd)
{
	ft_flag_check(my_printf);
	ft_print_p_pointer(my_printf, va_arg(printf_list, void *), fd);
}
