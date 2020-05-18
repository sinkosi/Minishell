/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:33:32 by sinkosi           #+#    #+#             */
/*   Updated: 2020/01/29 13:36:34 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	echo_path(char **str, int pos, char **g_envp){
	char	*env;

	env = env_find(str[pos] + 1, g_envp);
	ft_printf("%s", env);
}

static void	echo_args(char **str, int pos, char **g_envp)
{
	int	i;

	i = 0;
	if (str[pos][i] == '$')
		echo_path(str, pos, g_envp);
	else
	{
		if (i == 0 && SPECIAL_CHAR(str[pos][i]))
			i++;
		while(!SPECIAL_CHAR(str[pos][i]) && str[pos][i] != '\0')
			{
				ft_putchar(str[pos][i]);
				i++;
			}
	}
}

int			cmd_echo(char **args, char **g_envp)
{
	int i;
	int n;

	n = 0;
	if (!args[0])
	{
		ft_putchar('\n');
		return (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		n = 1;
	i = 0;
	if (n == 1)
		i++;
	while (args[i])
	{
		echo_args(args, i, g_envp);
		ft_putchar(' ');
		if (!args[i + 1] && n == 0)
			ft_putchar('\n');
		i++;
	}
	return (1);
}
