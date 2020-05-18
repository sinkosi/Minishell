#include "../includes/minishell.h"

//MEM LEAKS LIKELY. TEST UNSETENV
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

static void		remove_envp(int pos, char **g_envp)
{
	int	i;
	int	count;

	free(g_envp[pos]);
	g_envp[pos] = NULL;
	i = pos;
	count = pos + 1;
	while (g_envp[i + 1])
	{
		g_envp[i] = ft_strdup(g_envp[i + 1]);
		free(g_envp[i + 1]);
		i++;
		count++;
	}
	g_envp = reallocate_env(count - 1, g_envp);
}

int				ft_unsetenv(char **arg, char **g_envp)
{
	int	i;
	int	pos;

	i = 0;
	if (!arg[0])
	{
		ft_printf("unsetenv: %sPlease retry%s\n", M_YELLOW, M_RESET);
		return (1);
	}
	while (arg[i])
	{
		pos = pos_find(arg[i], g_envp);
		if (g_envp[pos])
			remove_envp(pos, g_envp);
		i++;
	}
	return (1);
}

int	ft_env_set(char	**args, char **g_envp)
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
		ft_path_env_set(args[0], args[1], g_envp);
	}
	return (1);
}
