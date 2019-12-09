/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:40:53 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:52:22 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_p_pointer(t_printf *my_printf, void *pointer, int fd)
{
	char	*str;

	str = ft_ltoa_base((intmax_t)pointer, 16);
	ft_flag_size(my_printf, ft_strlen(str));
	my_printf->field_width -= 2;
	if (my_printf->convert == 'p')
	{
		ft_putstr_fd("0x", fd);
		my_printf->f_return += 2;
	}
	ft_flag_width(my_printf, fd);
	if (my_printf->convert == 'P')
	{
		ft_putstr_fd("0X", fd);
		my_printf->f_return += 2;
	}
	ft_flag_precision(my_printf, str, fd);
	if (my_printf->convert == 'p')
		str = ft_strlowcase(str);
	ft_putstr_fd(str, fd);
	my_printf->f_return += ft_strlen(str);
	ft_flag_width(my_printf, fd);
	ft_strdel(&str);
}
