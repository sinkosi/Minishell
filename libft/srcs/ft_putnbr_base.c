/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:09:45 by sinkosi           #+#    #+#             */
/*   Updated: 2019/06/24 12:10:58 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	char	*str;
	int		i;

	str = "0123456789ABCDEF";
	i = 0;
	if (n <= -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n >= 2147483647)
	{
		ft_putstr("2147483647");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= base)
		ft_putnbr(n / base);
	i = (n % base);
	ft_putchar(str[i]);
}
