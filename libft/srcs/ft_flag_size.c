/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:51:44 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/07 08:40:19 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flag_size(t_printf *my_printf, size_t len)
{
	char	c;

	c = my_printf->convert;
	my_printf->prec_width -= len;
	my_printf->field_width -= len;
	if (my_printf->flag_space == 1 && my_printf->flag_plus == 0 &&
			(c == 'i' || c == 'd'))
		my_printf->field_width -= 1;
	if (my_printf->flag_plus != 0 && (c == 'i' || c == 'd'))
		my_printf->field_width -= 1;
	if ((my_printf->prec_width > 0) &&
		((c == 'i' || c == 'd' || c == 'x' || c == 'X' || c == 'o')
		|| c == 'O' || c == 'p' || c == 'u' || c == 'U'))
		my_printf->field_width -= my_printf->prec_width;
	if (my_printf->flag_hash == 1 && (c == 'o' || c == 'O') &&
			my_printf->prec_width <= 0)
		my_printf->field_width -= 1;
	else if (my_printf->flag_hash == 1 && (c == 'x' || c == 'X'))
		my_printf->field_width -= 2;
}
