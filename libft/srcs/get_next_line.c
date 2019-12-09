/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:30:35 by sinkosi           #+#    #+#             */
/*   Updated: 2019/07/17 10:17:59 by sinkosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_read - This function will read the buffer, determine if the character
**		being read is not a newline char '\n'. If it is not, then it will keep
**		reading. When it finds the newline char '\n' it returns (1).
**	If while reading, it finds the NULL Terminator char '\0', the function will
**		return a (0), letting the reader know that it is the END OF FILE.
**	If something out of the ordinary happens, then the function deems this to be
**		unexpected behaviour. It returns (-1) to let the system know it is in
**		error.
*/

static int		ft_read(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	else if (buffer[i] == '\0')
		return (0);
	else
		return (-1);
}

/*
** ft_get_line - This function's purpose is to read a line.It takes 3 parameters
**		as argument. It will take an int representing a file descriptor fd. It
**		takes a string 'char *' which it manipulates within the function. It
**		also takes a static char that's used through the running process to keep
**		track of where it is reading. This function calls ft_read in a while
**		loop to ensure that it is still appropriate to 'ft_get_line'.
**	HOW IT WORKS:
**	It places what is read and places it into a temporary string 'tmp'. The int
**		cfdp: (Control File Descriptor Process) is used to keep track of the
**		status of the file. If cfdp is > 0, then things are fine. If cfdp is 0
**		the file is done reading. If it is < 0, an error has occurred. The
**		function ft_read manages this concurrently. The 'tmp' string is given
**		the value of 'stat_char' in the fd (file descriptor). This function does
**		not free the string 'tmp', it deletes it at its address. The address of
**		the 'buffer' is also deleted of its contents.
**		The value of the CFDP determines how the function exits and whether to
**		GET_NEXT_LINE (1) / CLOSE (-1) / ERROR (-1)
*/

static int		ft_get_line(const int fd, char *buffer, char *stat_char[fd])
{
	int		cfdp;
	char	*tmp;

	while ((ft_read(buffer) != 1) && ((cfdp = read(fd, buffer, BUFF_SIZE)) > 0))
	{
		buffer[cfdp] = '\0';
		tmp = stat_char[fd];
		stat_char[fd] = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	ft_strdel(&buffer);
	if (cfdp < 0)
		return (-1);
	return (1);
}

/*
**	get_next_line - This function takes input from given/chosen file descriptor
**		It takes two parameters as an argument. The first is the file descriptor
**		that will be read, the second is the address of a pointer to a character
**		that will be used to save the line read from the file descriptor. When
**		the reading is complete the function returns its result without '\n'.
**	cfdp - Control File Descriptor Process: This is an integer for keeping track
**		of which file descriptor is currently being handled.
**	buffer - This is a string created in the function of size BUFF_SIZE, through
**		the function 'ft_strnew' which uses malloc.
**	str - This variable is called in an if statement. Its purpose is to take the
**		remainder of the string that 'ft_strchr' will return after finding the
**		'\n' character in string 'pnt_to_fd[fd]'.
**	tmp - This variable is called in an if statement after the 'str' variable.
**		Its purpose is to take the first part of the string pointed to by
**		'pnt_to_fd' after it has been separated by the '\n' character using the
**		'ft_strchr' function.
**	pnt_to_fd - This static char is used to keep track of where there the 'file
**		descriptor' is currently pointing. It moves as per the 'BUFF_SIZE' until
**		it reaches the 'EndOfFile', defined as the '0' point.
**	This function uses a ternary operator to control its final return. This is
**		due to norminette 25 line limit only. It used to be:
**		if (ft_strlen(*line) > 0)
**			return (1);
**		return (0);
*/

int				get_next_line(const int fd, char **line)
{
	int				cfdp;
	char			*buffer;
	char			*str;
	char			*tmp;
	static char		*pnt_to_fd[2147483647];

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	if (!pnt_to_fd[fd])
		pnt_to_fd[fd] = ft_strnew(0);
	if ((cfdp = ft_get_line(fd, buffer, pnt_to_fd)) == -1)
		return (-1);
	if ((str = ft_strchr(pnt_to_fd[fd], '\n')))
	{
		*line = ft_strsub(pnt_to_fd[fd], 0, str - pnt_to_fd[fd]);
		tmp = pnt_to_fd[fd];
		pnt_to_fd[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(pnt_to_fd[fd]);
	ft_strdel(&pnt_to_fd[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
