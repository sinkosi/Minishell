#include "libft.h"

static int		ft_newline(char **str, char **line, int fd, int bytes)
{
	char		*temp;
	int			i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		temp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		if (bytes == BUFF_SIZE)
			return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_newline(str, line, fd, bytes));
}
