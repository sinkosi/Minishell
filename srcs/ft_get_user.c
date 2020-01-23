/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:15:13 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/01 13:22:35 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_get_user(struct stat fstat, t_ls_flags *my_flags)
{
	char			*str;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	if (my_flags->flag_l == 1)
	{
		str = ft_strjoin(ft_strjoin(pw->pw_name, " "), gr->gr_name);
		my_flags->flag_g = 0;
	}
	else if (my_flags->flag_g == 1)
		str = gr->gr_name;
	return (ft_strjoin(str, " "));
}
