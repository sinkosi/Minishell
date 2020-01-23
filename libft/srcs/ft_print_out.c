/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:43:20 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:56:16 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_out(t_printf *my_printf, char *str, int fd)
{
	while (str[my_printf->i] != '%' && str[my_printf->i] != '\0')
	{
		ft_putchar_fd(str[my_printf->i], fd);
		my_printf->i += 1;
		my_printf->f_return += 1;
	}
}
