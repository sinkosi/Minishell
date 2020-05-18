/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:24:51 by sinkosi           #+#    #+#             */
/*   Updated: 2020/01/29 13:31:37 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define SPECIAL_CHAR(i) (i == '"' || i == '\'')

/*
** cmd_cd.c - This file handles directories and ensures that CWD
**	is updated if possible. An access call is made to determine if
**	we are dealing with a file, directory or have permission for our
**	actions. If this is correct then cd is updated.
*/
int		ft_cd(char **arg, char **g_envp);

/*
** cmd_echo.c - This file is the control file for the echo command.
**		The main function is called when the arg passed to it is echo.
**		This call is made by exec_builtin located in minishell.c. It also
**		uses get_env to use the current env.
*/
int		cmd_echo(char **args, char **g_envp);

/*
** ft_env.c - This file is for handling the env. As a point of clarity,
**		one must realise that pos_find and *env_find are the same
**		function and the only thing that is different is the return
**		value, with one returning a char* and the other returning an int.
*/
int		pos_find(char *str, char **g_envp);
char	*env_find(char *str, char **g_envp);
int		ft_path_len(char **path_str);
void	ft_path_env_set(char *str, char *env, char **g_envp);

/*
** ft_env_set.c - This file is for handling the env. The function ft_env_set
**		should not be confused with set_envp as this sets the env by taking
**		arguments with arg[0] being the first one to invoke it as a function.
**		The counter to this function is unsetenv, which will remove the env
**		that has been set.
**		These changes occur only for runtime and do not stay saved after runtime.
*/
int		ft_env_set(char **args, char **g_envp);
int		ft_unsetenv(char **arg, char **g_envp);


/*
**	ft_exec.c - 
*/
int		exec_bin(char **arg, char **g_envp);

/*
**	ft_free_array.c - This is a loop to free an array and ensure that all
**		memory allocated, reallocated is subsequently freed.
*/
void	ft_free_array(char **array);

#endif
