#include "../includes/minishell.h"

char	**arr_realloc(char **arr, char *str)
{
	char	**new;
	size_t	len;
	int		i;

	i = 0;
	len = arr_len(arr);
	new = (char**)malloc(sizeof(char*) * (len + 2));
	new[len + 1] = NULL;
	while (len--)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	arr_delete(&arr);
	return (new);
}
