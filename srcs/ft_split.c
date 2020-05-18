#include "../includes/minishell.h"

static size_t	ft_numwrds(char const *s)
{
	size_t		i;
	size_t		control;

	i = 0;
	control = 0;
	while (s[i] != '\0')
	{
		while (s[i] && ft_isspace(s[i] == 1))
			i++;
		if (s[i])
		{
			while (s[i] && !ft_isspace(s[i]))
				i++;
			control++;
		}
	}
	return (control);
}

char			**ft_split(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**ptopntr;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if (!(ptopntr = (char **)malloc(sizeof(char *) * (ft_numwrds(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			j = i;
			while (s[i] != '\0' && !ft_isspace(s[i]))
				i++;
			ptopntr[k++] = ft_strsub(s, j, i - j);
		}
	}
	ptopntr[k] = NULL;
	return (ptopntr);
}