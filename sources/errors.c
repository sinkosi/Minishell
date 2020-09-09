#include "../includes/minishell_error.h"

static void	terminate(void)
{
	ft_putendl(": a fatal error occured: shell terminated.");
	if (g_env && *g_env)
		arr_delete(&g_env);
	exit(EXIT_FAILURE);
}

void		arr_error(char *err, char ***arrdel, int f)
{
	ft_putendl(err);
	if (arrdel && *arrdel)
	{
		arr_delete(arrdel);
		**arrdel = NULL;
	}
	if (f)
		terminate();
}

void		error(char *err, int f)
{
	ft_putendl(err);
	if (f)
		terminate();
}
