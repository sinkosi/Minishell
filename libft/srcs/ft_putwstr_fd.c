/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:10:10 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/02 13:53:27 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putwstr_fd(wchar_t *wstr, int fd)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = (sizeof(wstr) / 2);
	while (i < n)
	{
		ft_putwchar_fd(wstr[i], fd);
		i++;
	}
}
