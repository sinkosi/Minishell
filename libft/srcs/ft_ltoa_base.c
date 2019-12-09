/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:07:09 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/26 14:18:40 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_absolute(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	ft_table_ref(char *str, long long value, int digits, int base)
{
	char	*tab;

	tab = "0123456789ABCDEF";
	str[digits] = '\0';
	digits--;
	while (digits >= 0)
	{
		str[digits] = tab[ft_absolute(value % base)];
		value = value / base;
		digits--;
	}
}

char		*ft_ltoa_base(intmax_t value, int base)
{
	char		*result;
	long long	digits;

	result = NULL;
	if (2 > base || base > 16)
		return (result);
	digits = ft_numlen_base(value, base);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result)
	{
		ft_table_ref(result, value, digits, base);
		if (value < 0 && base == 10)
			result[0] = '-';
	}
	return (result);
}
