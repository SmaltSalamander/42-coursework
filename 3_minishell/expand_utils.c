/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:44:46 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/03/10 13:57:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	variable_length(char *line, int i)
{
	int	k;

	k = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '$' || line[i] == '"'
			|| line[i] == '\'')
			return (k);
		i++;
		k++;
	}
	return (k);
}

char	*expand_var(int *i, char *new_line, char *line, t_data data)
{
	int		var_len;
	char	*variable;
	char	*var_value;
	int		k;

	var_len = variable_length(line, i[0]);
	variable = malloc(var_len + 1);
	ft_memcpy(variable, &line[i[0]], var_len);
	variable[var_len] = 0;
	i[0] = i[0] + var_len;
	var_value = ft_getenv(variable, data);
	if (var_value != NULL)
	{
		k = -1;
		while (var_value[++k])
			new_line = append_char(new_line, var_value[k]);
		i[1] += (int)ft_strlen(var_value);
	}
	free(variable);
	return (new_line);
}

char	*expand_exit_status(int *i, char *new_line, t_data data)
{
	char	*var_value;
	int		k;

	var_value = ft_itoa(data.exit_status);
	i[0] += 1;
	k = -1;
	while (var_value[++k])
		new_line = append_char(new_line, var_value[k]);
	i[1] += (int)ft_strlen(var_value);
	free(var_value);
	return (new_line);
}

char	*extract_pattern(int *i, char *line, char *new_line)
{
	char	*pattern;

	while (i[0])
	{
		if (line[i[0] - 1] == ' ')
			break ;
		i[0] = i[0] - 1;
		i[1] = i[1] - 1;
	}
	new_line[i[1]] = 0;
	pattern = ft_calloc(1, 1);
	while (line[i[0]] && line[i[0]] != ' ')
	{
		pattern = append_char(pattern, line[i[0]]);
		i[0] = i[0] + 1;
	}
	return (pattern);
}
