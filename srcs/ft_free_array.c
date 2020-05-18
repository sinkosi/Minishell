#include "../includes/minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}