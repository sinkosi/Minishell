/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:22:07 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 13:22:09 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	do_list(t_ls_flags *my_ls)
{
	my_ls->dir_list = (t_dir *)malloc(sizeof(t_dir));
	my_ls->dir_list->dir = ".";
	my_ls->dir_list->next = NULL;
}

void	ft_ls(t_ls_flags *my_ls)
{
	t_dir	*temp;

	temp = my_ls->dir_list;
	while (temp != NULL)
	{
		ft_ls_run_op(my_ls, temp->dir);
		temp = temp->next;
	}
}
