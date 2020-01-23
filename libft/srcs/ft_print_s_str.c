/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:19:50 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:55:02 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_s_str(t_printf *my_printf, char *str, int fd)
{
	char	*nullstr;

	nullstr = "(null)";
	if (str != NULL)
	{
		if (my_printf->prec_width > 0)
			str = ft_strndup(str, my_printf->prec_width);
		ft_flag_size(my_printf, ft_strlen(str));
		ft_flag_width(my_printf, fd);
		ft_flag_precision(my_printf, str, fd);
		ft_putstr_fd(str, fd);
		my_printf->f_return += ft_strlen(str);
		ft_flag_width(my_printf, fd);
	}
	else
	{
		ft_flag_size(my_printf, ft_strlen(nullstr));
		ft_flag_width(my_printf, fd);
		ft_flag_precision(my_printf, nullstr, fd);
		ft_putstr_fd(nullstr, fd);
		my_printf->f_return += ft_strlen(nullstr);
		ft_flag_width(my_printf, fd);
	}
}
