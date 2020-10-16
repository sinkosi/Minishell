#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H
# include "minishell.h"

# define NON_TERMINATE 0
# define TERMINATE 1

# define STREAM "error closing directory stream"
# define MEMORY "error allocating memory"

void  arr_error(char *err, char ***arrdel, int f);
void  error(char *err, int f);

# endif
