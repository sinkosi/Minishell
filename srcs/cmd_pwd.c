#include "../includes/minishell.h"

char    **cmd_pwd(char **args, char **env)
{
	char    buf[PATH_MAX + 1];
	int     i;

	i = 0;
	while(args[i] != '\0')
		i++;
	if (i == 1)
		ft_printf("%s\n", getcwd(buf, PATH_MAX));
	else if(i > 1)
		ft_printf("pwd: too many arguments\n");
	return (env);
}