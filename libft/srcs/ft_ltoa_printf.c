/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 08:36:23 by sinkosi           #+#    #+#             */
/*   Updated: 2019/08/07 08:37:00 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ltoa_printf(intmax_t nbr)
{
	char		*str;
	size_t		len;

	if (nbr < 0)
		nbr *= -1;
	len = ft_numlen(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0 && len >= 0)
	{
		str[len - 1] = ft_tochar(nbr % 10);
		nbr /= 10;
		len--;
	}
	return (str);
}
