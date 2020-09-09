#include "../includes/minishell.h"

size_t		arr_len(char **arr)
{
	size_t i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}
