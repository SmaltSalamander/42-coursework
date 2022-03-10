/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:35 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/16 15:27:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_quotes(char **line, int *close, char c, t_data *data)
{
	if (!find_if_closed(*line, close, c))
	{
		data->quote *= -1;
		return (1);
	}
	else
	{
		(*line)--;
		return (0);
	}
}

int	ft_specials(t_data *data, char	**line, int *close)
{
	char	c;

	c = **line;
	if (!c)
		return (1);
	(*line)++;
	if ((c == '\"' || c == '\'') && (c == *close || !*close))
		return (ft_handle_quotes(line, close, c, data));
	else if (data->quote == 1)
		return (flag_handling(c, data, line));
	else
	{
		(*line)--;
		return (0);
	}
}

int	check_flags(char	**tmp, char	*c, t_data *data, char ***arr)
{
	syntax_error_check(data);
	if (data->quote == 1)
	{
		if (data->srcin == 1 || data->srcin == 2)
			input_output(c, data, 0);
		else if (data->srcout == 1 || data->srcout == 2)
			input_output(c, data, 1);
		else if (data->srcerr == 1 || data->srcerr == 2)
			handle_errout(c, data);
		else if (data->pipes == 1)
		{
			add_element(tmp, arr, &(data->count), 1);
			data->commands = add_to_command(*arr, data);
			*arr = NULL;
			(data->count) = 0;
			data->pipes = 0;
			*tmp = append_char(*tmp, *c);
		}
		else
			*tmp = append_char(*tmp, *c);
	}
	else
		*tmp = append_char(*tmp, *c);
	return (1);
}

void	restore_flags(t_data *data, int pipes)
{
	if (data->namein || data->limiter)
	{
		if (data->namein)
			data->namein = cleanoff_trailing_whitespace(data->namein);
		data->srcin -= 2;
	}
	if (data->nameout)
	{
		if (data->nameout)
			data->nameout = cleanoff_trailing_whitespace(data->nameout);
		data->srcout -= 2;
	}
	if (data->nameerr)
	{
		if (data->nameerr)
			data->nameerr = cleanoff_trailing_whitespace(data->nameerr);
		data->srcerr -= 2;
	}
	data->pipes = pipes;
}

void	parse(t_data *data, char	*str)
{
	char	*tmp;
	char	**arr;
	int		quotes;

	quotes = 0;
	arr = NULL;
	tmp = ft_calloc(1, 1);
	while (*str)
	{
		if (data->quote == 1 && *tmp && (str[-1] == '\"' || str[-1] == '\''))
			add_element(&tmp, &arr, &(data->count), 2);
		while (data->quote == 1 && *str == ' ')
			str++;
		if (ft_specials(data, &str, &quotes))
			continue ;
		check_flags(&tmp, str, data, &arr);
		if (data->quote == 1 && *tmp && (str[1] == ' ' || ft_spec_char(str[1])))
			add_element(&tmp, &arr, &(data->count), 1);
		if (*str)
			str++;
	}
	add_element(&tmp, &arr, &(data->count), 0);
	data->commands = add_to_command(arr, data);
	restore_flags(data, arr_length(data->commands) - 1);
}
