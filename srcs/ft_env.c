#include "../includes/minishell.h"

int			find_position(char *str, char **g_envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envp[i])
	{
		temp = ft_strjoin(str, "=");
		if (ft_strnequ(g_envp[i], temp, ft_strlen(temp)))
		{
			free(temp);
			return (i);
		}
		free(temp);
		i++;
	}
	return (i);
}

static char	**allocate_envp(int new_pos, char **g_envp)
{
	char	**new_envp;
	int		i;

	i = -1;
	new_envp = (char **)malloc(sizeof(char *) * (new_pos + 1));
	while (g_envp[++i] && i < new_pos)
	{
		new_envp[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
	}
	free(g_envp[i]);
	return (new_envp);
}

char	*env_find(char *str, char **g_envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (g_envp[i])
	{
		temp = ft_strjoin(str, "=");
		if (ft_strnequ(g_envp[i], temp, ft_strlen(temp)))
		{
			free(temp);
			return (ft_strchr(g_envp[i], '=') + 1);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

void		set_envp(char *str, char *value, char **g_envp)
{
	int		pos;
	char	*temp;

	pos = find_position(str, g_envp);
	temp = ft_strjoin("=", value);
	if (g_envp[pos])
	{
		free(g_envp[pos]);
		if (value)
			g_envp[pos] = ft_strjoin(str, temp);
	}
	else
	{
		g_envp = allocate_envp(pos + 1, g_envp);
		if (value)
			g_envp[pos] = ft_strjoin(str, temp);
		g_envp[pos + 1] = NULL;
	}
	free(temp);
}