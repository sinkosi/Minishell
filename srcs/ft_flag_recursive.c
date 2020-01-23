/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:21:27 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 14:19:20 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_flag_recursive(t_dir *list, t_ls_flags *my_ls)
{
	t_dir *temp;

	temp = list;
	while (temp != NULL)
	{
		if (temp->ft_is_dir == 1 && temp->dir[0] != '.')
			ft_ls_run_op(my_ls, temp->path);
		temp = temp->next;
	}
}
