/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:18:08 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/11 11:18:59 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

size_t		ft_ls_strlen(t_dir *list)
{
	t_dir		*temp;
	struct stat	ft_stat;
	char		*str;
	size_t		len;

	temp = list;
	len = 0;
	while (temp != NULL)
	{
		lstat(temp->path, &ft_stat);
		str = ft_ltoa_base(ft_stat.st_size, 10);
		if (ft_strlen(str) > len)
			len = ft_strlen(str);
		temp = temp->next;
	}
	return (len);
}
