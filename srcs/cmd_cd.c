#include "../includes/minishell.h"

static void	change_dir(char *home_path, char **g_envp)
{
	char	*cwd;
	char	buff[1024];

	cwd = getcwd(buff, 1024);
	if (chdir(home_path) == 0)
		ft_path_env_set("OLDPWD", cwd, g_envp);
	else
	{
		ft_dprintf(2, "%s", home_path);
		if (access(home_path, F_OK) == -1)
			ft_dprintf(2, ": no such file or directory\n");
		else if (access(home_path, R_OK) == -1)
			ft_dprintf(2, ": $sPermission Failure$s\n", M_RED, M_RESET);
		else
			ft_dprintf(2, ": not a directory\n");
	}
}

static void	home_view(char *home_path, char *path, char **g_envp)
{
	char	*temp;

	temp = ft_strdup(home_path);
	temp = ft_strcat(home_path, "/");
	path += 2;
	temp = ft_strcat(temp, path);
	change_dir(temp, g_envp);
	free(temp);
}

int			ft_cd(char **arg, char **g_envp)
{
	char	*home_path;

	home_path = env_find("HOME", g_envp);
	if (!arg[0] || (arg[0][0] == '~' && !arg[0][1]))
	{
		change_dir(home_path, g_envp);
		return (1);
	}
	else
	{
		if (arg[0][0] == '~' && arg[0][1] == '/')
		{
			home_view(home_path, arg[0], g_envp);
			return (1);
		}
		else if (arg[0][0] == '-' && !arg[0][1])
		{
			change_dir(env_find("OLDPWD", g_envp), g_envp);
			return (1);
		}
		change_dir(arg[0], g_envp);
	}
	return (1);
}
