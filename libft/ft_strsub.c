/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:20:49 by nmaila            #+#    #+#             */
/*   Updated: 2019/07/12 14:20:51 by nmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t    i;
	char			*str;

	i = 0;
  if (!s || !(str = (char*)malloc(sizeof(*str) * (len + 1))) ||
                  start > ft_strlen(s))
          return (NULL);
  while (s[start + i] && i < len)
  {
          str[i] = s[start + i];
          i++;
  }
  str[i] = '\0';
  return (str);
}
