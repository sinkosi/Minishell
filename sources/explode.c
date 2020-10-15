#include "../includes/minishell.h"

static void	addition(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];
	char *check;

	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	if (value)
		ft_strcat(new, value);
	else
	{
		if (!ptr[1])
			ft_strcat(new, "$");
	}
	if ((check = ft_strchr(ptr, ' ')))
		ft_strcat(new, check);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

static void	explode_validate(char **str)
{
	int		j;
	char	*ptr;
	char	*temp;
	char	*value;
	char	*string;

	j = 0;
	ptr = NULL;
	while ((*str)[j])
	{
		if ((ptr = ft_strchr(&(*str)[j], '$')) && (*str)[0])
		{
			if (!(string = ft_strchr(ptr, ' ')))
				string = ft_strchr(ptr, '\0');
			j = (ptr - *str) + 1;
			temp = ft_strsub(ptr, 1, string - (ptr + 1));
			value = search_par(g_env, temp, NULL, SEARCH_VAL);
			addition(value, str, ptr);
			ft_strdel(&temp);
		}
		else
			j++;
	}
}

void		explode(char **args)
{
	if (!args || !*args || !**args)
		return ;
	if (args[1])
		args++;
	else
		return ;
	while (*args)
	{
		explode_validate(args);
		args++;
	}
}
