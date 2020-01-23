/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:44:04 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 14:13:12 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_mod(t_printf *my_printf, int fd)
{
	ft_flag_size(my_printf, 1);
	ft_flag_width(my_printf, fd);
	ft_putchar_fd('%', fd);
	ft_flag_width(my_printf, fd);
	my_printf->f_return += 1;
}
