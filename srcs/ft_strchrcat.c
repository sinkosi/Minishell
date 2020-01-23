/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:22:50 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 13:22:51 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_strchrcat(char *dst, const char src)
{
	size_t i;

	i = ft_strlen(dst);
	if (src != '\0')
		dst[i] = src;
	dst[i + 1] = '\0';
	return (dst);
}
