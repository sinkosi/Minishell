/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lf_float_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:16:11 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:16:28 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_size_significand(t_printf *my_printf, char *str, int fd)
{
	ft_flag_size(my_printf, ft_strlen(str));
	if (my_printf->flag_minus == 0 && my_printf->flag_zero == 0
		&& my_printf->flag_hash == 1)
		ft_flag_width(my_printf, fd);
}

static void	ft_size_mantissa(t_printf *my_printf, char *str, int fd)
{
	ft_flag_size(my_printf, ft_strlen(str));
	if (my_printf->flag_minus == 0 && my_printf->flag_zero == 0
		&& my_printf->flag_hash == 1)
		ft_flag_width(my_printf, fd);
}

void		ft_print_lf_float(t_printf *my_printf, long double n, int fd)
{
	char		*str;
	char		*mantissa;
	intmax_t	a;

	a = n;
	str = ft_ltoa_base(n, 10);
	n = ft_fabs(n) - ft_fabs(a);
	if (my_printf->prec_width <= 0)
		my_printf->prec_width = 6;
	a = ft_power_ten(ft_fabs(n), my_printf->prec_width);
	mantissa = ft_ltoa_base(a, 10);
	ft_flag_size(my_printf, ft_strlen(str));
	ft_size_significand(my_printf, str, fd);
	ft_size_mantissa(my_printf, mantissa, fd);
	ft_flag_width(my_printf, fd);
	ft_putstr_fd(str, fd);
	my_printf->f_return += ft_strlen(str);
	ft_putstr_fd(".", fd);
	my_printf->f_return += 1;
	ft_putstr_fd(mantissa, fd);
	my_printf->f_return += ft_strlen(mantissa);
	if (my_printf->field_width > 0)
		ft_flag_width(my_printf, fd);
	ft_strdel(&str);
}
