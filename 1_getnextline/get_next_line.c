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

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#ifdef BUFFER_SIZE

void	*ft_calloc(unsigned long nmemb, unsigned long size)
{
	char			*mem;
	unsigned long	n;
	unsigned long	counter;

	counter = 0;
	mem = (char *)malloc(size);
	if (mem == NULL)
		return (NULL);
	n = nmemb * size;
	while (n > 0)
	{
		*(char *)(mem + counter) = 0;
		n--;
		counter++;
	}
	return (mem);
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

#endif