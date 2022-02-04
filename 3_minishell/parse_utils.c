/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:44:20 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/02 19:06:52 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_if_closed(char	*line, int *isclosing)
{
	line++;
	if (*isclosing == 1)
	{
		*isclosing = 0;
		return (0);
	}
	while (*line)
	{
		if (*line == '\'')
		{
			*isclosing = 1;
			return (0);
		}
		line++;
	}
	return (1);
}

int	ft_spec_char(char c)
{
	if (c == '$' || c == '|' || c == '<' || c == '>' || c == '\'')
		return (1);
	else
		return (0);
}

char	*cleanoff_trailing_whitespace(char	*str)
{
	char	*temp;
	int		counter;

	counter = ft_strlen(str) - 1;
	while (str[counter] == ' ')
		counter--;
	if (counter != ft_strlen(str) - 1)
	{
		temp = ft_substr(str, 0, counter + 1);
		free(str);
		return (temp);
	}
	else
		return (str);
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
	if (arr)
		free(arr);
	return (temparr);
}
