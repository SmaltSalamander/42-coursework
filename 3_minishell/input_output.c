/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:12:52 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/15 08:13:00 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_input(t_data data)
{
	int	fd_file_in;

	if (data.srcin != 0)
	{
		if (!access(data.namein, F_OK))
		{
			fd_file_in = open(data.namein, 0, 0666);
			if (fd_file_in == -1)
			{
				perror(data.namein);
				return (1);
			}
			else
			{
				dup2(fd_file_in, 0);
				close(fd_file_in);
			}
		}
		else
		{
			perror(data.namein);
			return (1);
		}
	}
	return (0);
}

void	redirect_output(t_data data)
{
	int	fd_file_out;
	int	fd_file_err;

	if (data.srcout != 0)
	{
		fd_file_out = open_file_write(data.nameout, data.srcout);
		if (fd_file_out == -1)
			perror(data.nameout);
		else
		{
			dup2(fd_file_out, 1);
			close(fd_file_out);
		}
	}
	if (data.srcerr != 0)
	{
		fd_file_err = open_file_write(data.nameerr, data.srcerr);
		if (fd_file_err == -1)
			perror(data.nameerr);
		else
		{
			dup2(fd_file_err, 2);
			close(fd_file_err);
		}
	}
}
