/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:20:01 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:14:03 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_convert(t_printf *my_printf, va_list printf_list,
		char *str, int fd)
{
	ft_flag_reset(my_printf);
	while (str[my_printf->i] != '\0' &&
		(ft_strchr_bool(PARSE, str[my_printf->i]) == 0))
	{
		if (ft_strchr_bool(FLAGS, str[my_printf->i]) == 1)
			ft_flag_set(my_printf, str);
		else if (my_printf->field_width < ft_atoi(&str[my_printf->i]) &&
			(str[my_printf->i - 1] == '0' || (ft_isdigit(str[my_printf->i - 1])
			== 0)) && str[my_printf->i - 1] != '.')
			my_printf->field_width = ft_atoi(&str[my_printf->i]);
		else if (str[my_printf->i - 1] == '.')
			my_printf->prec_width = ft_atoi(&str[my_printf->i]);
		my_printf->i += 1;
	}
	if (ft_strchr_bool(PARSE, str[my_printf->i]))
	{
		my_printf->convert = str[my_printf->i];
		my_printf->i += 1;
		ft_handler_convert(my_printf, printf_list, fd);
	}
	else
		return ;
}
