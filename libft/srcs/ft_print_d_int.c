/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:47:16 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/16 08:55:41 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_d_int(t_printf *my_printf, intmax_t n, int fd)
{
	char	*str;

	if (n < 0)
	{
		my_printf->flag_plus = -1;
		n *= -1;
	}
	str = ft_ltoa_base(n, 10);
	ft_flag_size(my_printf, ft_strlen(str));
	ft_flag_space(my_printf, fd);
	if (my_printf->prec_width > 0)
		my_printf->field_width -= my_printf->prec_width;
	ft_flag_width(my_printf, fd);
	ft_flag_plus(my_printf, fd);
	ft_flag_precision(my_printf, str, fd);
	if (my_printf->field_width == 0 && my_printf->prec_width > 0)
		my_printf->prec_width = 0;
	ft_flag_precision(my_printf, str, fd);
	my_printf->f_return += ft_strlen(str);
	ft_putstr_fd(str, fd);
	ft_flag_width(my_printf, fd);
	ft_strdel(&str);
}
