#include "../includes/minishell.h"

int cmd_echo(char **args)
{
	int i;
	int n;

	n = 0;
	if (!args[0])
	{
		ft_putchar('\n');
		return (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		n = 1;
	i = 0;
	if (n == 1)
		i++;
	while (args)
	{
		echo_args(args, i);
		if (!args[i + 1] && n == 0)
			ft_putchar('\n');
		i++;
	}
}

static void	echo_args(char **str, int pos)
{
	
}