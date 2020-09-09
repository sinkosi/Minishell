#include "../includes/minishell.h"

static void	pos_find(char *value, size_t value_len, char *newstr, int index)
{
	char	*original_val;
	char	*temp;

	original_val = ft_strchr(g_env[index], '=') + 1;
	if (!original_val)
		return ;
	else if (ft_strlen(original_val) >= value_len)
		ft_strcpy(original_val, value);
	else
	{
		temp = ft_strdup(newstr);
		free(g_env[index]);
		g_env[index] = temp;
	}
}

void		ft_setenv(char *var, char *value, size_t var_len, size_t value_len)
{
	char	newstr[var_len + value_len + 2];
	int		i;

	if (!var || !value || !*var || !*value)
		error("Incorrect setenv format", NON_TERMINATE);
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], var, var_len) && (g_env[i][var_len] == '='))
			break ;
		i++;
	}
	ft_bzero(newstr, sizeof(newstr));
	ft_strcat(newstr, var);
	ft_strcat(newstr, "=");
	ft_strcat(newstr, value);
	if (g_env[i])
		pos_find(value, value_len, newstr, i);
	else
		g_env = arr_realloc(g_env, newstr);
}

int			setenv_checker(char **args)
{
	if (arr_len(args) != 3)
		error("Incorrect amount of arguments", 0);
	else
		ft_setenv(args[1], args[2], ft_strlen(args[1]), ft_strlen(args[2]));
	return (1);
}
