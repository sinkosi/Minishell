#include "../includes/minishell.h"

static char		**reallocate_env(int new_size, char **g_envp)
{
	char	**new_env;
	int		i;

	i = -1;
	new_env = (char**)malloc(sizeof(char*) * (new_size + 1));
	while (g_envp[++i] && i < new_size)
	{
		new_env[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
	}
	free(g_envp);
	new_env[i] = NULL;
	return (new_env);
}

static void		remove_envp(int var_pos, char **g_envp)
{
	int	i;
	int	var_count;

	free(g_envp[var_pos]);
	g_envp[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envp[i + 1])
	{
		g_envp[i] = ft_strdup(g_envp[i + 1]);
		free(g_envp[i + 1]);
		i++;
		var_count++;
	}
	g_envp = reallocate_env(var_count - 1, g_envp);
}

int				ft_unsetenv(char **arg, char **g_envp)
{
	int	i;
	int	var_pos;

	i = 0;
	if (!arg[0])
	{
		ft_printf("unsetenv: %sPlease retry%s", M_YELLOW, M_RESET);
		return (1);
	}
	while (arg[i])
	{
		var_pos = find_position(arg[i], g_envp);
		if (g_envp[var_pos])
			remove_envp(var_pos, g_envp);
		i++;
	}
	return (1);
}

int	ft_env_set(char	**args)
{
	if(!args[0] || (args[0] && !args[1]))
	{
		ft_dprintf(2, "setenv: %sWarning: Not enough arguments%s\n", M_YELLOW, M_RESET);
		return (1);
	}
	if (args[0] && args[1])
	{
		if(args[2])
		{
			ft_dprintf(2, "setenv: %sWarning: exceeds argument limit%s\n", M_YELLOW, M_RESET);
			return (1);
		}
		ft_path_env_set(args[0], args[1]);
	}
	return (1);
}
