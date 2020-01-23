/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_c_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:45:27 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:50:16 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_handler_c_char(t_printf *my_printf, va_list printf_list, int fd)
{
	if (my_printf->h == 1)
		return ;
	else if (my_printf->h == 2)
		return ;
	else if (my_printf->l == 2)
		return ;
	else if (my_printf->j == 1)
		return ;
	else if (my_printf->z == 1)
		return ;
	ft_flag_check(my_printf);
	if (my_printf->l != 1)
		ft_print_c_char(my_printf, va_arg(printf_list, int), fd);
}
