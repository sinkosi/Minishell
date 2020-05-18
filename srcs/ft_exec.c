#include "../includes/minishell.h"

static int	ft_exec(char *path, char **arg, char **g_envp)
{
	int			pid;

	pid = fork();
	if (pid == 0)
		execve(path, arg, g_envp);
	else if (pid < 0)
		ft_dprintf(2, "Unexpected failure, please retry");
	wait(&pid);
	return (1);
}

static int	exec_path(char **arg, char **path, char **g_envp)
{
	int			i;
	struct stat	fstat;
	char		*temp;
	char		*str;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		str = ft_strjoin(temp, arg[0]);
		free(temp);
		if (lstat(str, &fstat) != -1)
		{
			if (fstat.st_mode & S_IXUSR)
			{
				ft_exec(str, arg, g_envp);
				free(str);
				return (1);
			}
		}
		free(str);
		i++;
	}
	return (0);
}

int			exec_bin(char **arg, char **g_envp)
{
	char		**path;
	struct stat	fstat;
	int			ret;

	ret = 0;
	if (lstat(arg[0], &fstat) != -1)
	{
		if (fstat.st_mode & S_IXUSR)
		{
			ft_exec(arg[0], arg, g_envp);
			return (1);
		}
	}
	path = ft_strsplit(env_find("PATH", g_envp), ':');
	if (!path || path[0] == NULL)
		ft_dprintf(2, "$> Unfortunately the command was not found :( : %s\n", arg[0]);
	else
	{
		ret = exec_path(arg, path, g_envp);
		if (ret == 0)
			ft_dprintf(2, "$> The '%s' command was not found!\n", arg[0]);
	}
	ft_free_array(path);
	return (1);
}