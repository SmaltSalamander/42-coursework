/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:46:20 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/15 14:47:12 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error_check(t_data *data)
{
	int	i;
	int	j;

	if (data->srcout > 2)
		i = 0;
	else
		i = data->srcout;
	if (data->srcin > 2)
		j = 0;
	else
		j = data->srcin;
	if ((i > 0 && j > 0) || data->pipes > 1)
	{
		printf("syntax error\n");
		return ;
	}
}

int	find_if_closed(char	*line, int *isclosing, char c)
{
	if (*isclosing == line[-1])
	{
		*isclosing = 0;
		return (0);
	}
	while (*line)
	{
		if (*line == c)
		{
			*isclosing = line[0];
			return (0);
		}
		line++;
	}
	return (1);
}
