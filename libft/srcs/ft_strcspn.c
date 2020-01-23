/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:29:13 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/09 16:02:48 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (ft_strchr(charset, *s))
			return (result);
		else
		{
			s++;
			result++;
		}
	}
	return (result);
}
