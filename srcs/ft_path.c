#include "../includes/minishell.h"

int ft_path_len(char **path_str)
{
	int	i;

	i = 0;
	while(path_str[i] != NULL)
		i++;
	return (i);
}

void	ft_path_env_set(char *str, char *env)
{
	int		i;
	char	*new_env;

	
}
