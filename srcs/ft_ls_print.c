/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:15:26 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/16 12:40:57 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_print_dir(t_dir *my_ls)
{
	t_dir	*temp;
	int		i;

	temp = my_ls;
	i = 0;
	while (temp != NULL)
	{
		ft_printf("%s", temp->dir);
		i++;
		temp = temp->next;
		if (temp != NULL && (i % 8 != 0))
			ft_putstr("  ");
		else if (temp != NULL && (i % 8 == 0))
			ft_putchar('\n');
	}
}

void		ft_ls_print(t_dir *my_ls, t_ls_flags *my_ls_flags, char *path)
{
	if (my_ls_flags->flag_t == 1)
		ft_sort_list(&my_ls, ft_time_cmp, 0);
	if (my_ls_flags->flag_r == 1)
		ft_rev_list(&my_ls);
	if (my_ls_flags->flag_recursive == 1)
		ft_printf("%s", ft_strjoin(path, ":\n"));
	if (my_ls_flags->flag_l == 1 || my_ls_flags->flag_g == 1)
		ft_ls_p_long_list(my_ls, my_ls_flags);
	else
		ft_print_dir(my_ls);
	ft_putchar('\n');
	if (my_ls_flags->flag_recursive == 1)
		ft_flag_recursive(my_ls, my_ls_flags);
}
