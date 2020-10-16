/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kngalalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:10:42 by kngalalu          #+#    #+#             */
/*   Updated: 2019/07/31 10:10:46 by kngalalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		len;
	size_t		end;

	start = 0;
	if (s == NULL)
		return (NULL);
  len = 0;
  start = 0;
  end = (ft_strlen(s) - 1);
  if (end > ft_strlen(s))
          return (ft_strnew(0));
  while ((s[start] >= '\t' && s[start] <= '\r') || s[start] == ' ')
          start++;
  if ((start - 1) == end)
          return (ft_strnew(0));
  while ((s[end] >= '\t' && s[end] <= '\r') || s[end] == ' ')
          end--;
  len = (end - start + 1);
  return ((ft_strsub(s, start, len)));
}
