#include "libft.h"

void  ft_putstrx3(char *s1, char *s2, char *s3)
{
        if (!s1 && !s2 && !s3)
                return ;
        ft_putstr(s1);
        ft_putstr(s2);
        ft_putstr(s3);
}
