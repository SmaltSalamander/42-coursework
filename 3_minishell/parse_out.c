/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:06:37 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/20 16:32:54 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_errout(t_data *data, char	**line, char type)
{
	if (data->nameerr)
	{
		if (!access(data->nameerr, F_OK) && data->srcerr % 2 == 1)
			unlink(data->nameerr);
		open(data->nameerr, O_CREAT);
		free(data->nameerr);
		data->nameerr = NULL;
	}
	if (line[0][0] == type)
	{
		data->srcerr = 2;
		(*line)++;
	}
	else
		data->srcerr = 1;
}

void	ft_handle_output(t_data *data, char	**line, char type)
{
	if (data->nameout)
	{
		if (!access(data->nameout, F_OK) && data->srcout % 2 == 1)
			unlink(data->nameout);
		open(data->nameout, O_CREAT, O_RDWR);
		free(data->nameout);
		data->nameout = NULL;
	}
	if (line[0][0] == type)
	{
		data->srcout = 2;
		(*line)++;
	}
	else
		data->srcout = 1;
}

void	handle_errout(char *c, t_data *data)
{
	if (!data->nameerr)
		data->nameerr = ft_calloc(1, 1);
	data->nameerr = append_char(data->nameerr, *c);
	if (c[1] == ' ' || ft_spec_char(c[1]) || !c[1])
		data->srcerr += 2;
}
