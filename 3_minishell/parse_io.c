/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:06:37 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/02 18:07:19 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_input(t_data *data, char	**line, char type)
{
	if (data->namein)
	{
		free(data->namein);
		data->namein = NULL;
	}
	if (data->limiter)
	{
		free(data->limiter);
		data->limiter = NULL;
	}
	if (line[0][1] == type)
	{
		data->srcin = 2;
		(*line)++;
	}
	else
		data->srcin = 1;
}

int	ft_handle_output(t_data *data, char	**line, char type)
{
	if (data->nameout)
	{
		free(data->nameout);
		data->nameout = NULL;
	}
	if (line[0][1] == type)
	{
		data->srcout = 2;
		(*line)++;
	}
	else
		data->srcout = 1;
}

int	check_limiter(int	*temp_fds, t_data *data)
{
	char	*s;

	while (get_next_line(temp_fds[0], &s))
	{
		if (!ft_memcmp(s, data->limiter, ft_strlen(data->limiter)))
		{
			close(temp_fds[0]);
			free(s);
			unlink("temp_file");
			return (1);
		}
		write(temp_fds[1], s, ft_strlen(s));
		write(temp_fds[1], "\n", 1);
		free(s);
		return (0);
	}
}

void	ft_here_doc_exc(t_data *data, char *c)
{
	char	buff[1];
	int		temp_fds[2];
	int		limlen;

	if (!data->limiter)
		data->limiter = ft_calloc(1, 1);
	data->limiter = append_char(data->limiter, *c);
	if (c[1] == ' ' || ft_spec_char(c[1]))
	{
		data->srcin += 2;
	}
}

void	input_output(char *c, t_data *data, int inout)
{
	if (inout == 0)
	{
		if (data->srcin == 2)
			return (ft_here_doc_exc(data, c));
		if (!data->namein)
			data->namein = ft_calloc(1, 1);
		data->namein = append_char(data->namein, *c);
		if (c[1] == ' ' || ft_spec_char(c[1]) || !c[1])
			data->srcin += 2;
	}
	else if (inout == 1)
	{
		if (!data->nameout)
			data->nameout = ft_calloc(1, 1);
		data->nameout = append_char(data->nameout, *c);
		if (c[1] == ' ' || ft_spec_char(c[1]) || !c[1])
			data->srcout += 2;
	}
}
