/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:04:30 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/31 10:17:56 by kngalalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
  unsigned char *str1;
  unsigned char *str2;

  i = 0;
  str1 = (unsigned char *)s1;
  str2 = (unsigned char *)s2;
  while (str1[i] != '\0' && str1[i] == str2[i])
  {
          i++;
  }
  return (str1[i] - str2[i]);
}
