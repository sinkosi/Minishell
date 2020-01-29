/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:24:51 by sinkosi           #+#    #+#             */
/*   Updated: 2020/01/23 11:25:32 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <limits.h>

# define SPECIAL_CHAR(i) (i == '"' || i == '\'')

char    **cmd_pwd(char **args, char **env);
int     cmd_echo(char **args);


#endif
