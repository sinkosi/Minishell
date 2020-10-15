#include "../includes/minishell.h"

char	**arr_dup(char **arr)
{
	char	**dup;
	char	**dup_z;
	size_t	len;

	if (!(len = arr_len(arr)))
		return (NULL);
	if (!(dup = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	dup_z = dup;
	dup[len] = NULL;
	while (len--)
		*dup++ = ft_strdup(*arr++);
	return (dup_z);
}
