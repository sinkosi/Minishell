#include "../includes/minishell.h"

int	print_env(char **ep)
{
	int	i;

	i = 0;
	while (ep[i])
		ft_putendl(ep[i++]);
	return (1);
}
