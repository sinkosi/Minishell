/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:20:31 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 14:19:38 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_time_flag(t_ls_flags *my_ls, t_dir *temp)
{
	if (my_ls->flag_u == 1)
		temp->ft_time = my_ls->ft_ls_stat.st_atime;
	else if (my_ls->flag_c == 1)
		temp->ft_time = my_ls->ft_ls_stat.st_ctime;
	else
		temp->ft_time = my_ls->ft_ls_stat.st_mtime;
}

void		ft_ls_run_op(t_ls_flags *my_ls, char *path)
{
	t_dir	*list;
	t_dir	*temp;

	list = NULL;
	if ((my_ls->dir_path = opendir(path)) != NULL)
	{
		while ((my_ls->dirent_dir = readdir(my_ls->dir_path)) != NULL)
		{
			if (my_ls->dirent_dir->d_name[0] != '.' || my_ls->flag_a == 1)
			{
				temp = (t_dir *)malloc(sizeof(t_dir));
				temp->dir = my_ls->dirent_dir->d_name;
				temp->path = ft_strjoin(ft_strjoin(path, "/"),
						my_ls->dirent_dir->d_name);
				lstat(temp->path, &my_ls->ft_ls_stat);
				ft_time_flag(my_ls, temp);
				if (S_ISDIR(my_ls->ft_ls_stat.st_mode) == 1)
					temp->ft_is_dir = 1;
				temp->next = list;
				list = temp;
			}
		}
		ft_sort_list(&list, ft_dir_strcmp, 0);
		ft_ls_print(list, my_ls, path);
	}
}
