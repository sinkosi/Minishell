#include "../includes/minishell.h"

void	ft_unsetenv(char *var_name)
{
	int		i;
	size_t	v_len;

	i = 0;
	v_len = ft_strlen(var_name);
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], var_name, v_len) && g_env[i][v_len] == '=')
			break ;
		i++;
	}
	if (g_env[i])
	{
		free(g_env[i]);
		g_env[i] = NULL;
		while (g_env[++i])
			g_env[i - 1] = g_env[i];
		g_env[i - 1] = NULL;
	}
}

int		unsetenv_checker(char **args)
{
	if (args[1])
		ft_unsetenv(args[1]);
	else
		error("No arguments.", 0);
	return (1);
}
