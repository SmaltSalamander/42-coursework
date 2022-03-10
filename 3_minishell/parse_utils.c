/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:44:20 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/16 14:40:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_spec_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	else
		return (0);
}

char	*cleanoff_trailing_whitespace(char	*str)
{
	char	*temp;

	temp = ft_strtrim(str, " ");
	free(str);
	return (temp);
}

// if array add if not create; make as big as count, copy over stuff and add new
char	**add_to_array(char	*str, char **arr, int	*count)
{
	char	**temparr;

	temparr = malloc(sizeof(char *) * (*count + 2));
	if (!arr)
		temparr[0] = str;
	else
	{
		ft_memmove(temparr, arr, sizeof(char *) * *count);
		temparr[*count] = str;
	}
	temparr[*count + 1] = NULL;
	*count = *count + 1;
	if (arr)
		free(arr);
	return (temparr);
}

char	***add_to_command(char	**arr, t_data *data)
{
	char	***temparr;
	int		len;

	if (!data->commands)
	{
		temparr = ft_calloc(sizeof(char **), 2);
		temparr[0] = arr;
		return (temparr);
	}
	else
	{
		len = arr_length(data->commands);
		temparr = malloc(sizeof(char **) * (len + 2));
		ft_memmove(temparr, data->commands, sizeof(char **) * len);
		temparr[len] = arr;
	}
	temparr[len + 1] = NULL;
	if (data->commands)
		free(data->commands);
	return (temparr);
}

int	flag_handling(char c, t_data *data, char **line)
{
	if (c == '1' && **line == '>')
		ft_handle_output(data, line, *((*line)++));
	else if (c == '2' && **line == '>')
		ft_set_errout(data, line, *((*line)++));
	else if (c == '<')
		ft_handle_input(data, line, c);
	else if (c == '>')
		ft_handle_output(data, line, c);
	else if (c == '|')
		data->pipes = data->pipes + 1;
	else
	{
		(*line)--;
		return (0);
	}
	return (1);
}
