#ifndef MINI_H
# define MINI_H
# include "../libft/libft.h"
# include "minishell_error.h"
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>

# define SEARCH_OFF 0
# define SEARCH_ON  01
# define SEARCH_VAL 02

# ifndef ARG_MAX
# define ARG_MAX (256 * 1024)
# endif
 
//void  arr_error(char *err, char ***arrdel, int f);
//void  error(char *err, int f);


char		**g_env;

char		*search_par(char **env, char *env_var, char *arg, int flag);
char		**arr_dup(char **arr);
size_t		arr_len(char **arr);
void		arr_delete(char ***delete);
char		**arr_realloc(char **arr, char *str);
void		ft_setenv(char *var, char *value, size_t var_len, size_t value_len);
void		ft_unsetenv(char *varname);
int			ft_cd(char *path);
char		**parser(char *input);
void		explode(char **args);
int			unsetenv_checker(char **args);
int			setenv_checker(char **args);
int			ft_echo(char **args);
int			print_env(char **ep);
int			permission(char *str);
int			permission_dir(char *str);

#endif
