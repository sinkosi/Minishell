/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 08:42:14 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/07 08:46:05 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_num_ulen(uintmax_t n, int base)
{
	size_t	i;

	i = 0;
	while (n /= base)
		i++;
	return (i + 1);
}

char			*ft_ultoa(uintmax_t nbr, int base)
{
	char		*str;
	size_t		len;

	if (nbr < 0)
		nbr *= -1;
	len = ft_num_ulen(nbr, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0 && len >= 0)
	{
		str[len - 1] = ft_tochar(nbr % base);
		nbr /= base;
		len--;
	}
	return (str);
}
