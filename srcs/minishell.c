#include "../includes/minishell.h"

static void	get_path(char **args, char **path)
{
	char *tmp;

	if (!(tmp = search_par(g_env, "PATH", args[0], SEARCH_ON)))
	{
		*path = args[0];
		return ;
	}
	else
		tmp = ft_strrealloc(tmp, args[0]);
	ft_strcpy(*path, tmp);
	free(tmp);
}

static int	run(char **args, int status)
{
	char	tmp_path[PATH_MAX];
	pid_t	pid;
	char	*path;

	path = tmp_path;
	get_path(args, &path);
	if (!permission(path))
		return (1);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, g_env);
		ft_putstr("Error opening: ");
		ft_putendl(*args);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	return (1);
}

static int	run_exec(char **args)
{
	int		status;

	status = 1;
	if (!args || !*args || !**args)
		return (1);
	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
		return (print_env(g_env));
	else if (ft_strcmp(*args, "setenv") == 0)
		return (setenv_checker(args));
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_cd(args[1]));
	else if (ft_strcmp(*args, "unsetenv") == 0)
		return (unsetenv_checker(args));
	else if (ft_strcmp(*args, "echo") == 0)
		return (ft_echo(args));
	else
		return (run(args, status));
}

static void	ft_loop(void)
{
	char	*cmd_line;
	char	**args;
	char	*trimed_input;
	int		status;

	status = 1;
	cmd_line = NULL;
	while (status)
	{
		ft_putstr("msh > ");
		if (get_next_line(STDIN_FILENO, &cmd_line) == -1)
			error("error reading stdin.", NON_TERMINATE);
		trimed_input = ft_strtrim(cmd_line);
		ft_strdel(&cmd_line);
		args = parser(trimed_input);
		ft_strdel(&trimed_input);
		explode(args);
		status = run_exec(args);
		if (args)
			arr_delete(&args);
	}
}

int			main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	g_env = arr_dup(env);
	ft_loop();
	arr_delete(&g_env);
	//sleep(1000);
	return (0);
}
