/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ws_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:04:36 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:04:48 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_ws_str(t_printf *my_printf, wchar_t *str, int fd)
{
	char	*nullstr;

	nullstr = "(null)";
	if (str != NULL)
	{
		ft_flag_size(my_printf, sizeof(str));
		ft_flag_width(my_printf, fd);
		ft_flag_precision(my_printf, (char *)str, fd);
		ft_putwstr_fd(str, fd);
		my_printf->f_return += sizeof(str);
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
