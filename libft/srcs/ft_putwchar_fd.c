/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:56:45 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:49:00 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_putchar_wfd(int n, int fd)
{
	write(fd, &n, 1);
}

void		ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 127)
		ft_putchar_wfd(wc, fd);
	else if (wc <= 2047)
	{
		ft_putchar_wfd(((wc >> 6) + 0xC0), fd);
		ft_putchar_wfd(((wc & 0x3F) + 0x80), fd);
	}
	else if (wc <= 65535)
	{
		ft_putchar_wfd(((wc >> 12) + 0xE0), fd);
		ft_putchar_wfd((((wc >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_wfd(((wc & 0x3F) + 0x80), fd);
	}
	else if (wc <= 1114111)
	{
		ft_putchar_wfd(((wc >> 18) + 0xF0), fd);
		ft_putchar_wfd((((wc >> 12) & 0x3F) + 0x80), fd);
		ft_putchar_wfd((((wc >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_wfd(((wc & 0x3F) + 0x80), fd);
	}
}
