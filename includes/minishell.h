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
# include <dirent.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define SPECIAL_CHAR(i) (i == '"' || i == '\'')
# define SEARCH_OFF 0
# define SEARCH_ON  01
# define SEARCH_VAL 02

# ifndef ARG_MAX
# define ARG_MAX (256 * 1024)
# endif

# define NON_TERMINATE 0
# define TERMINATE 1

# define STREAM "error closing directory stream"
# define MEMORY "error allocating memory"

void  arr_error(char *err, char ***arrdel, int f);
void  error(char *err, int f);

/*
** cmd_cd.c - This file handles directories and ensures that CWD
**	is updated if possible. An access call is made to determine if
**	we are dealing with a file, directory or have permission for our
**	actions. If this is correct then cd is updated.
*/
int		ft_cd(char *path);

/*
** cmd_echo.c - This file is the control file for the echo command.
**		The main function is called when the arg passed to it is echo.
**		This call is made by exec_builtin located in minishell.c. It also
**		uses get_env to use the current env.
*/
int		ft_echo(char **args);

/*
** ft_env.c - This file is for handling the env. As a point of clarity,
**		one must realise that pos_find and *env_find are the same
**		function and the only thing that is different is the return
**		value, with one returning a char* and the other returning an int.
*/
void		ft_unsetenv(char *varname);

/*
** ft_setenv.c - This file is for handling the env. The function ft_env_set
**		should not be confused with set_envp as this sets the env by taking
**		arguments with arg[0] being the first one to invoke it as a function.
**		The counter to this function is unsetenv, which will remove the env
**		that has been set.
**		These changes occur only for runtime and do not stay saved after runtime.
*/
void		ft_setenv(char *var, char *value, size_t var_len, size_t value_len);//int		ft_unsetenv(char **arg, char **g_envp);


/*
**	ft_exec.c - 
*/
//int		exec_bin(char **arg, char **g_envp);

/*
**	ft_free_array.c - This is a loop to free an array and ensure that all
**		memory allocated, reallocated is subsequently freed.
*/
//void	ft_free_array(char **array);


char		**g_env;

char		*search_par(char **env, char *env_var, char *arg, int flag);
char		**arr_dup(char **arr);
size_t		arr_len(char **arr);
void		arr_delete(char ***delete);
char		**arr_realloc(char **arr, char *str);
//void		ft_setenv(char *var, char *value, size_t var_len, size_t value_len);
//void		ft_unsetenv(char *varname);
//int			ft_cd(char *path);
char		**parser(char *input);
void		explode(char **args);
int			unsetenv_checker(char **args);
int			setenv_checker(char **args);
//int			ft_echo(char **args);
int			print_env(char **ep);
int			permission(char *str);
int			permission_dir(char *str);
char		*ft_strrealloc(char *s1, char *s2);



#endif
