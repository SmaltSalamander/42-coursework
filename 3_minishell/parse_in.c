/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:06:37 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/16 18:24:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_input(t_data *data, char	**line, char type)
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
	if (line[0][0] == type)
	{
		data->srcin = 2;
		(*line)++;
	}
	else
		data->srcin = 1;
}

void	ft_here_doc_exc(t_data *data, char *c)
{
	if (!data->limiter)
		data->limiter = ft_calloc(1, 1);
	data->limiter = append_char(data->limiter, *c);
	if (c[1] == ' ' || ft_spec_char(c[1]) || !c[1])
	{
		data->limiter = cleanoff_trailing_whitespace(data->limiter);
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
		{
			data->namein = cleanoff_trailing_whitespace(data->namein);
			data->srcin += 2;
		}
	}
	else if (inout == 1)
	{
		if (!data->nameout)
			data->nameout = ft_calloc(1, 1);
		data->nameout = append_char(data->nameout, *c);
		if (c[1] == ' ' || ft_spec_char(c[1]) || !c[1])
		{
			data->nameout = cleanoff_trailing_whitespace(data->nameout);
			data->srcout += 2;
		}
	}
}
