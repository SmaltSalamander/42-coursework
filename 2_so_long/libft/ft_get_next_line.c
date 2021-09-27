/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:57:38 by sbienias          #+#    #+#             */
/*   Updated: 2021/06/03 10:57:38 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 10

char	*join_strings(char *s1, char *s2)
{
	char	*str;
	size_t	s2len;
	size_t	s1len;
	size_t	counter;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = ft_calloc(sizeof(char), s1len + s2len + 1);
	if (str != NULL)
	{
		counter = 0;
		while (counter++ < s1len)
			*(str + counter - 1) = *(s1 + counter - 1);
		counter = 0;
		while (counter++ < s2len)
			*(str + s1len + counter - 1) = *(s2 + counter - 1);
		*(str + s1len + s2len) = '\0';
	}
	free(s1);
	return (str);
}

int	create_line(char **line, char **tempbuff)
{
	int		counter;
	char	*tmpstr;

	counter = 0;
	while (*(*tempbuff + counter) != '\n' && *(*tempbuff + counter) != '\0')
		counter++;
	if (*(*tempbuff + counter) == '\n')
	{
		tmpstr = ft_substr(*tempbuff, 0, counter);
		free(*line);
		*line = tmpstr;
		tmpstr = ft_strdup(*tempbuff + counter + 1);
		free(*tempbuff);
		*tempbuff = tmpstr;
	}
	else
	{
		free(*line);
		tmpstr = ft_strdup(*tempbuff);
		*line = tmpstr;
		free(*tempbuff);
		*tempbuff = NULL;
	}
	return (1);
}

int	return_value(char **line, char **fdbuffer, int btinbuff, int fd)
{
	int		returnval;

	if (btinbuff < 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	else if (fdbuffer[fd])
		returnval = (create_line(line, &fdbuffer[fd]));
	if (fdbuffer[fd] == NULL && btinbuff == 0)
	{
		return (0);
	}
	return (returnval);
}

char	*populate_buffer_line(char *buffline, char *buffer)
{
	char	*temp;

	if (buffline == NULL)
	{
		temp = ft_strdup(buffer);
	}
	else
	{
		temp = join_strings(buffline, buffer);
		buffline = temp;
	}
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	static char	*lines[1024];
	char		*buffer;
	int			size;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	*line = ft_calloc(1, 1);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		lines[fd] = populate_buffer_line(lines[fd], buffer);
		if (ft_strchr(lines[fd], '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (return_value(line, lines, size, fd));
}
