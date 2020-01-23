/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:14:24 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/16 10:33:17 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_get_time(struct stat fstat, t_dir *temp)
{
	char	t_fmt[13];
	char	*str;
	char	buf[64];
	size_t	len;

	(void)fstat;
	str = ctime(&temp->ft_time);
	ft_memcpy(t_fmt, &str[4], 12);
	t_fmt[12] = '\0';
	ft_printf("%s %s", t_fmt, temp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		len = readlink(temp->path, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}
