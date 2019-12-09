/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:29:33 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/12 14:08:36 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n <= -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n >= 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	a = ft_tochar(n % 10);
	ft_putchar_fd(a, fd);
}
