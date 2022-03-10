/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:10:46 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/05 12:16:32 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_handle_quote(char **new_line, char current_char, int *flag, \
char quote)
{
	new_line[0] = append_char(new_line[0], current_char);
	if (flag[2] == '0')
		flag[2] = (unsigned char)quote;
	else if (flag[2] == quote)
		flag[2] = '0';
}

void	expand_handle_dollar(char **new_line, char *line, t_data *data, \
int *i)
{
	if (i[2] == '\'')
		new_line[0] = append_char(new_line[0], line[i[0]]);
	i[0]++;
	if (i[2] == '"' || i[2] == '0')
	{
		if (line[i[0]] == '?')
			new_line[0] = expand_exit_status(i, new_line[0], *data);
		else
			new_line[0] = expand_var(i, new_line[0], line, *data);
	}
}

int	expand_handle_star(char **new_line, char *line, int *i)
{
	if (i[2] == '\'' || i[2] == '"')
		new_line[0] = append_char(new_line[0], line[i[0]]);
	else
	{
		new_line[0] = expand_wildcard(i, new_line[0], line);
		return (1);
	}
	return (0);
}

void	expand_loop(char **new_line, char *line, int *i, t_data *data)
{
	if (line[i[0]] == '"')
		expand_handle_quote(new_line, line[i[0]], i, '"');
	else if (line[i[0]] == '\'')
		expand_handle_quote(new_line, line[i[0]], i, '\'');
	else if (line[i[0]] == '$')
	{
		if (line[i[0] + 1] == 0 || line[i[0] + 1] == ' '
			|| line[i[0] + 1] == '"')
			new_line[0] = append_char(new_line[0], line[i[0]]);
		else
		{
			expand_handle_dollar(new_line, line, data, i);
			return ;
		}
	}
	else if (line[i[0]] == '*')
	{
		if (expand_handle_star(new_line, line, i) == 1)
			return ;
	}
	else
		new_line[0] = append_char(new_line[0], line[i[0]]);
	i[0]++;
	i[1]++;
}

char	*expand_variables(char *line, t_data *data)
{
	char	*new_line;
	int		i[3];

	i[2] = '0';
	new_line = NULL;
	if (ft_strchr((const char *)line, '$') == NULL
		&& ft_strchr((const char *)line, '*') == NULL)
		return (line);
	else
	{
		i[0] = 0;
		i[1] = 0;
		new_line = malloc(ft_strlen(line));
		*new_line = 0;
		while (line[i[0]])
			expand_loop(&new_line, line, i, data);
	}
	free(line);
	return (new_line);
}
