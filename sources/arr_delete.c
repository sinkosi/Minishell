#include "../includes/minishell.h"

void	arr_delete(char ***delete)
{
	int i;

	i = 0;
	while ((*delete)[i])
		free((*delete)[i++]);
	free(*delete);
}
