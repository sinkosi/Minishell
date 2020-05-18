#include "../includes/minishell.h"

/*
** ft_env.c contains arr_alloc which is exactly the same except
**	this contains arr[i] = NULL;
*/
static char		**arr_realloc(int size, char **g_envp)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * (size + 1));
	while (g_envp[i] && i < size)
	{
		arr[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
		i++;
	}
	free(g_envp);
	arr[i] = NULL;
	return (arr);
}

static void		env_del(int pos, char **g_envp)
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
	g_envp = arr_realloc(count - 1, g_envp);
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
			env_del(pos, g_envp);
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
