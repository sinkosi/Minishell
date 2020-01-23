/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:54:44 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/16 12:45:50 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_help_call(char *str)
{
	ft_printf("Usage: ft_ls [OPTION]... [FILE]...\nList information about the");
	ft_printf(" FILEs (the current directory by default).\nSort entries");
	ft_printf(" alphabetically if none of -'t' is specified.\n\nMandatory");
	ft_printf("	arguments to long options are mandatory for short options ");
	ft_printf("too.\n-a, --all	do not ignore entries starting with .\n");
	ft_printf("-l		use a long listing format\n");
	ft_printf("-r, --reverse	reverse order while sorting\n");
	ft_printf("-R, --recursive	list subdirectories recursively\n");
	ft_printf("-t		sort by modification time, newest first\n");
	ft_printf("	-%s	display this help and exit\n\n", str);
	ft_printf("Exit status:\n 0	if %sOK%s,\n", M_GREEN, M_RESET);
	ft_printf(" 1	if %sminor%s problems ", M_YELLOW, M_RESET);
	ft_printf("e.g., cannot access subdirectory),\n");
	ft_printf(" 2	if %sserious%s trouble (e.g., cannot", M_RED, M_RESET);
	ft_printf("access command-line argument).\n");
	return (0);
}

static int	ft_illegal(char *str, int n, int option)
{
	if (option == 1)
	{
		ft_printf("ft_ls: illegal option -- %c\n", str[n]);
		ft_printf("usage: ft_ls [-%s] [file ...]\n", LS_FLAGS);
	}
	else if (option == 2)
	{
		ft_printf("ft_ls: option '--%c' is ambiguous;\n", str[n + 1]);
		ft_printf("Try 'ft_ls --help' for more information.\n");
	}
	return (0);
}

static int	ft_assist(char *parse, int i)
{
	if (ft_strcmp(parse + i, "-help") == 0)
		return (ft_help_call(parse + i));
	else if (parse[i] == '-' && parse[i + 1] != '\0'
		&& (ft_strchr_bool(LS_FLAGS, parse[i + 1]) == 1))
		return (ft_illegal(parse, i, 2));
	else
		return (ft_illegal(parse, i, 1));
}

static void	ft_time_assist(t_ls_flags *ft_ls, char *parse, int i)
{
	if (parse[i] == 'u')
		ft_ls->flag_u = 1;
	else if (parse[i] == 'c')
		ft_ls->flag_c = 1;
}

int			ft_ls_flag_set(t_ls_flags *ft_ls, char *parse)
{
	int		i;

	i = 1;
	while (parse[i] != '\0')
	{
		if (parse[i] == 'l')
			ft_ls->flag_l = 1;
		else if (parse[i] == 'R')
			ft_ls->flag_recursive = 1;
		else if (parse[i] == 'a')
			ft_ls->flag_a = 1;
		else if (parse[i] == 'r')
			ft_ls->flag_r = 1;
		else if (parse[i] == 't')
			ft_ls->flag_t = 1;
		else if (parse[i] == 'g')
			ft_ls->flag_g = 1;
		else if (parse[i] == 'c' || parse[i] == 'u')
			ft_time_assist(ft_ls, parse, i);
		else
			return (ft_assist(parse, i));
		i++;
	}
	return (1);
}
