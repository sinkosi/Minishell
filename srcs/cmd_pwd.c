/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:37:30 by sinkosi           #+#    #+#             */
/*   Updated: 2020/01/29 13:38:05 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//# include <limits.h>

char	**cmd_pwd(char **args, char **env)
{
	char	buf[PATH_MAX + 1];
	int		i;

	i = 0;
	while (args[i] != NULL)
		i++;
	if (i == 1)
		ft_printf("%s\n", getcwd(buf, PATH_MAX));
	else if (i > 1)
		ft_printf("pwd: too many arguments\n");
	return (env);
}
