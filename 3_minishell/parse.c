/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:35 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/02 18:16:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_specials(t_data *data, char	**line, int *elecount, int *isclosed)
{
	if (**line == '<')
		ft_handle_input(data, line, **line);
	else if (**line == '>')
		ft_handle_output(data, line, **line);
	else if (**line == '|')
		data->pipes = data->pipes + 1;
	else if (**line == '\'')
		return (find_if_closed(*line, isclosed));
	return (0);
}

void	syntax_error_check(t_data *data)
{
	int	sum;
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
	sum = i + j;
	if (i > 0 && j > 0 || data->pipes > 1)
	{
		printf("syntax error\n");
		return ;
	}
}

void	check_flags(char	**tmp, char	*c, t_data *data, int *count)
{
	syntax_error_check(data);
	if (data->srcin == 1 || data->srcin == 2)
		input_output(c, data, 0);
	else if (data->srcout == 1 || data->srcout == 2)
		input_output(c, data, 1);
	else if (data->pipes == 1)
	{
		*tmp = cleanoff_trailing_whitespace(*tmp);
		data->commands = add_to_array(*tmp, data->commands, count);
		*tmp = ft_calloc(1, 1);
		data->pipes = 0;
		(*count)++;
		*tmp = append_char(*tmp, *c);
	}
	else
		*tmp = append_char(*tmp, *c);
}

void	restore_flags(t_data *data, int	pipes)
{
	if (data->namein || data->limiter)
		data->srcin -= 2;
	if (data->nameout)
		data->srcout -= 2;
	data->pipes = pipes;
}

void	parse(t_data *data, char	*line)
{
	char	*tmp;
	int		elecount;
	char	*cpy;
	int		quotes;
	int		status;

	elecount = 0;
	quotes = 0;
	status = 0;
	cpy = line;
	tmp = ft_calloc(1, 1);
	while (*cpy)
	{
		while (*cpy == ' ')
			cpy++;
		if (ft_spec_char(*cpy))
			status = ft_specials(data, &cpy, &elecount, &quotes);
		else
		{
			check_flags(&tmp, cpy, data, &elecount);
			if (cpy[1] == ' ')
				tmp = append_char(tmp, cpy[1]);
		}
		cpy++;
	}
	tmp = cleanoff_trailing_whitespace(tmp);
	data->commands = add_to_array(tmp, data->commands, &elecount);
	restore_flags(data, elecount);
}
