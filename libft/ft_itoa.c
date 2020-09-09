/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:54:52 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/31 10:14:05 by kngalalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      digits(int n)
{
        size_t i;

        i = 1;
        while (n /= 10)
                i++;
        return (i);
}

char		*ft_itoa(int n)
{
	char          *str;
  size_t        len;
  unsigned int  nbr;

	len = digits(n);
  nbr = n;
  if (n < 0)
  {
          nbr = -n;
          len++;
  }
  if (!(str = ft_strnew(len)))
          return (NULL);
  str[--len] = nbr % 10 + '0';
  while (nbr /= 10)
          str[--len] = nbr % 10 + '0';
  if (n < 0)
          str[0] = '-';
  return (str);
}
