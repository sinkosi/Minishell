/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:33:39 by sinkosi           #+#    #+#             */
/*   Updated: 2019/09/11 10:33:52 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>

# define LS_FLAGS "Racglrtu"

typedef struct		s_dir
{
	char			*dir;
	char			*path;
	time_t			ft_time;
	int				ft_is_dir;
	struct s_dir	*next;
}					t_dir;
/*
**	Flags:
**	-A - Shows all files (including hidden files), but doesn't show the "."
**		and ".." directories. (Bonus)
**	-G - Shows normal files, but adds colour. (Bonus) **
**	-R - Shows all files recursively.
**	-a - Shows all files including "." and "..".
**	-f - Shows normal files, unsorted. (Bonus)	**
**	-l - Shows files in long format.
**	-n - Shows UID and GID in long format as a number. (Bonus) **
**	-p - Adds a '/' to the back of directory names. (Bonus)	**
**	-r - Reverses the output.
**	-t - Sorts files according to time.
*/

typedef struct		s_ls_flags
{
	int				flag_recursive;
	int				flag_a;
	int				flag_c;
	int				flag_g;
	int				flag_l;
	int				flag_r;
	int				flag_t;
	int				flag_u;
	char			*path;
	DIR				*dir_path;
	struct dirent	*dirent_dir;
	struct stat		ft_ls_stat;
	t_dir			*dir_list;
}					t_ls_flags;

/*
** ************************************************************************	*
**									LS_HANDLERS								*
** ************************************************************************	*
*/
/*
** FT_FLAG_INIT - This function takes the struct ft_ls as arguments and
**		initialises all its members	to zero.
*/
void				ft_flag_init(t_ls_flags *ft_ls);

/*
** FT_FLAG_SET - This function takes the struct ft_ls and a char as argument.
**		It then compares the char to see if it is valid input. It then turns
**		the appropriate flag on. Turning a flag on, would be to change the
**		value from 0 to 1. If an invalid char is provided then it will output
**		that an error has occured and the flag parsed is invalid.
*/
int					ft_ls_flag_set(t_ls_flags *ft_ls, char *parse);

void				ft_flag_recursive(t_dir *list, t_ls_flags *my_ls);

char				*ft_get_user(struct stat fstat, t_ls_flags *my_flags);

/*
** FT_D
*/
void				ft_dir_current(int argc, char **argv, struct dirent *attr);

/*
** ************************************************************************	*
**									LS_PRINTERS								*
** ************************************************************************	*
*/

void				ft_ls_p_permission(t_dir *ft_ls,
		struct stat ft_ls_stat);
void				ft_ls_p_groupname(char *str);

void				ft_ls_p_long_list(t_dir *my_ls, t_ls_flags *my_flags);

/*
** ************************************************************************	*
**									LS_SORTERS								*
** ************************************************************************	*
*/
void				ft_sort_list(t_dir **head, int (*cmp)(t_dir, t_dir),
		int done);

void				ft_rev_list(t_dir **head_ref);

int					ft_time_cmp(t_dir dir1, t_dir dir2);

int					ft_dir_strcmp(t_dir dir1, t_dir dir2);

void				do_ls(char *dir, t_ls_flags *e);

void				ft_get_time(struct stat fstat, t_dir *temp);

void				ft_ls_print(t_dir *my_ls, t_ls_flags *my_ls_flags,
		char *path);

int					add_args(t_ls_flags *e, char *arg);

void				ft_ls_run_op(t_ls_flags *my_ls, char *path);

char				*ft_strchrcat(char *dst, const char src);

void				do_list(t_ls_flags *my_ls);

void				ft_ls(t_ls_flags *my_ls);

void				ft_dir_current(int argc, char **argv,
		struct dirent *attr);

size_t				ft_ls_strlen(t_dir *list);

#endif
