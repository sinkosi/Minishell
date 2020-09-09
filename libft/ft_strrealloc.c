#include "libft.h"

char      *ft_strrealloc(char *s1, char *s2)
{
    char *new;
  
    new = ft_strjoin(s1, s2);
    ft_strdel(&s1);
    return (new);
}

