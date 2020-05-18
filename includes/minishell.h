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
# include "../libft/includes/libft.h"

# define SPECIAL_CHAR(i) (i == '"' || i == '\'')

/*
** cmd_cd.c - 
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
** cmd_pwd.c - This command is to change the present working directory
*/
char	**cmd_pwd(char **args, char **env);

/*
** ft_env.c - This file is for handling the env
*/
int		find_position(char *str, char **g_envp);
char	*env_find(char *str, char **g_envp);
void	set_envp(char *str, char *value, char **g_envp);


/*
** ft_env_set.c - 
*/
int		ft_env_set(char **args);
int		ft_unsetenv(char **arg, char **g_envp);


/*
**	ft_exec.c - 
*/
int		exec_bin(char **arg, char **g_envp);

/*
** ft_path.c - 
*/
int		ft_path_len(char **path_str);
void	ft_path_env_set(char *str, char *env);

/*
** ft_display.c
*/
void	ft_welcome(int var);
void	ft_help(void);

/*
** ft_split.c - Works similar to ft_strsplit in libft except
**	that the characters it will split by are in the ft_isspace
**	domain;
*/
char	**ft_split(char const *s);

#endif
