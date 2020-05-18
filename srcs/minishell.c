/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:23:23 by sinkosi           #+#    #+#             */
/*   Updated: 2020/01/29 13:37:11 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_env(char **g_envp)
{
	int		i;

	i = 0;
	while (g_envp[i])
	{
		ft_putendl(g_envp[i]);
		i++;
	}
}

static int	exec_builtin(char **arg, char **g_envp)
{
	if (!arg || arg[0] == NULL)
		return (1);
	else if (ft_strcmp(arg[0], "exit") == 0)
	{
		ft_printf("%sExiting\n%sPRODUCT OF WETHINKCODE\n%sSINKOSI & KNGALALU\n%s", M_RESET, M_CYAN, M_MAGENTA, M_RESET);
		return (0);
	}
	else if (ft_strcmp(arg[0], "cd") == 0)
		return (ft_cd(arg, g_envp));
	else if (ft_strcmp(arg[0], "echo") == 0)
		return (cmd_echo(arg + 1, g_envp));
	else if (ft_strcmp(arg[0], "setenv") == 0)
		return (ft_env_set(arg + 1, g_envp));
	else if (ft_strcmp(arg[0], "unsetenv") == 0)
		return (ft_unsetenv(arg + 1, g_envp));
	else if (ft_strcmp(arg[0], "env") == 0)
	{
		print_env(g_envp);
		return (1);
	}
	else
		return (exec_bin(arg, g_envp));
}

static void	ft_loop(char **envp)
{
	char	*cmd_line;
	char	**arg;
	int		status;
	char	**g_envp;

	status = 1;
	g_envp = envp;
	while (status)
	{
		cmd_line = readline("\033[32m$>\033[36m ");
		if (cmd_line && *cmd_line)
			add_history(cmd_line);
		arg = ft_strsplit(cmd_line, ' ');
		ft_strdel(&cmd_line);
		status = exec_builtin(arg, g_envp);
		ft_free_array(arg);
		//ft_free_array(g_envp);
	}
}

static void	copy_envp(int argc, char **argv, char **envp)//, char **g_envp)
{
	int		i;
	char **g_envp;

	g_envp = envp;
	//g_envp = (char **)malloc(sizeof(char *) * (ft_path_len(envp) + 1));
	i = 0;
	while (envp[i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
		{
			ft_free_array(g_envp);
			write(1, "\n", 1);
			exit(0);
		}
		i++;
	}
	g_envp[i] = NULL;
	(void)argc;
	(void)argv;
}

int			main(int argc, char **argv, char **envp)
{
	copy_envp(argc, argv, envp);
	ft_loop(envp);
//	ft_free_array(g_envp);
	return (0);
}