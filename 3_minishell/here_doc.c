/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:55:07 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/01/23 11:55:07 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(t_data data)
{
	printf("minishell: warning: here-document delimited by "
		"end-of-file (wanted '%s')\n", data.limiter);
	return (-1);
}

void	write_to_file(int temp_fd, char *buff)
{
	write(temp_fd, buff, ft_strlen(buff));
	write(temp_fd, "\n", 1);
}

int	ft_here_doc(t_data data)
{
	int		temp_fd;
	char	*buff;

	temp_fd = open_file_write("temp_file123", 1);
	if (temp_fd == -1)
	{
		close(temp_fd);
		perror("temp_file");
		return (-1);
	}
	while (1)
	{
		buff = readline(">");
		if (!buff)
			return (error(data));
		if (ft_memcmp(data.limiter, buff, ft_strlen(data.limiter) + 1))
			write_to_file(temp_fd, buff);
		else
		{
			close(temp_fd);
			return (0);
		}
	}
}
