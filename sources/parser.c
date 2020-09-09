#include "../includes/minishell.h"

static void	remove_chr(char *p)
{
	char	f;
	int		i;

	f = 0;
	while (p && *p)
	{
		i = 0;
		while (*p && *p != '"' && *p != '\'')
			p++;
		if (*p == '"' || *p == '\'')
		{
			if (f == 0)
				f = *p;
			else if (f == *p)
				f = 0;
		}
		if (f == *p || f == 0)
			while (p && p[i++])
				p[i - 1] = p[i];
		else
			p++;
	}
}

static void	qoutes_checker(char **input, char *f)
{
	while (**input && !(ft_isspace(**input) && *f == 0))
	{
		if (**input == '\'' || **input == '"')
		{
			if (*f == **input)
				*f = 0;
			else if (*f == 0)
				*f = **input;
		}
		(*input)++;
	}
}

static void	t_expander(char **str)
{
	char *home;
	char *temp;

	home = search_par(g_env, "HOME", NULL, SEARCH_VAL);
	temp = ft_strrealloc(home, &(*str)[1]);
	ft_strdel(str);
	*str = temp;
}

static void	checker(char **args, char *input, char *f)
{
	char	*ip;
	char	*op;
	int		i;

	i = 0;
	while (*input)
	{
		ip = input;
		qoutes_checker(&input, f);
		op = input;
		if (!(args[i] = ft_strsub(ip, 0, op - ip)))
		{
			arr_error("error allocating memory", &args, NON_TERMINATE);
			return ;
		}
		if (args[i][0] == '~' && (!args[i][1] || args[i][1] == '/'))
			t_expander(&args[i]);
		remove_chr(args[i]);
		i++;
		while (ft_isspace(*input))
			input++;
	}
	args[i] = NULL;
}

char		**parser(char *input)
{
	char	**args;
	char	f;

	f = 0;
	if (!input || !*input)
		return (NULL);
	if (!(args = (char**)malloc(sizeof(char*) * (ARG_MAX))))
	{
		error("error allocating memory", NON_TERMINATE);
		return (NULL);
	}
	checker(args, input, &f);
	if (f)
	{
		ft_putendl("Error: unmatched qoutes.");
		if (args && *args)
			arr_delete(&args);
		return (NULL);
	}
	return (args);
}
