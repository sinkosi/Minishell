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

#include <readline/readline.h>
//char	**g_envp;

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
		ft_putendl("The program is exiting... 100%");
		return (0);
	}
	else if (ft_strcmp(arg[0], "cd") == 0)
		return (ft_cd(arg, g_envp));
	else if (ft_strcmp(arg[0], "echo") == 0)
		return (cmd_echo(arg + 1, g_envp));
	else if (ft_strcmp(arg[0], "setenv") == 0)
		return (ft_env_set(arg + 1));
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

static void	ft_loop(char **g_envp)
{
	char	*cmd_line;
	char	**arg;
	int		status;

	status = 1;
	while (status)
	{
		cmd_line = readline("\033[32m$>\033[36m ");
		if (cmd_line && *cmd_line)
			add_history(cmd_line);
		arg = ft_strsplit(cmd_line, ' ');
		free(cmd_line);
		status = exec_builtin(arg, g_envp);
		ft_free_array(arg);
	}
}

static void	copy_envp(int ac, char **av, char **envp, char **g_envp)
{
	int		i;

	(void)ac;
	(void)av;
	g_envp = (char **)malloc(sizeof(char *) * (ft_path_len(envp) + 1));
	i = 0;
	while (envp[i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
		{
			//ft_memdel((void**)(g_envp));
			ft_free_array(g_envp);
			write(1, "\n", 1);
			exit(0);
		}
		//ft_putendl(g_envp[i]);
		i++;
	}
	//ft_putendl(g_envp[0]);
	g_envp[i] = NULL;
}

int			main(int ac, char **av, char **envp)
{
	char **g_envp;

	//char *str = readline("Test>> ");
	copy_envp(ac, av, envp, g_envp);
	ft_loop(g_envp);
	ft_free_array(g_envp);
	return (1);
}
/*
static void	run_loop(void)
{
	char	*str;
	//char	**loop_array;
	int		status;

	status = -1;
	while(status != 0)
	{
		ft_dprintf(1, "$>");
		get_next_line(0, &str);
		//loop_array = ft_strsplit(str, ' ');
		ft_strdel(&str);
		//status = exec_builtin(loop_array);
		status = 0;
	}
}*/

/*

int	main(int argc, char **argv, char **envp)
{
	//ft_welcome(1);
	ft_printf("---  \n");
	ft_printf("!   ! !\\   ! ! /   /\\   --- !\n");
	ft_printf("--- ! ! \\  ! !/   /  \\  !__ !\n");
	ft_printf("  ! ! !  \\ ! !\\   \\  /    ! !\n");
	ft_printf("__! ! !   \\! ! \\   \\/   --- !\n");
	if (argc != 3)
	{
		ft_printf("Not enough arguments\n");	
		return (1);
	}
	else*/
/*	char *word = envp[0];
	if (word)
	{
		ft_printf("word exists\n");
	}
	if (argc != 0)
	{
		//run_loop();
		//argv[0] = "What is in argc number 3\n";
		//ft_printf("%s", argv[0]);
		ft_printf("%s\n", argv[0]);
		ft_printf("str\n");
		ft_printf("%d\n", sizeof(envp));
		unsigned long i = 0;
		while (i < sizeof(envp))
		{
			ft_printf("%s\n", envp[i]);
			i++;
		}
		return (0);
	}
	return (0);
}
*/