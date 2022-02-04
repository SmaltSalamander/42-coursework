/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:10:46 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/01/15 17:58:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_char(char *line, char c)
{
	char	*new_line;
	int		len;

	len = (int)ft_strlen(line);
	new_line = malloc(len + 2);
	ft_memcpy(new_line, line, len);
	new_line[len] = c;
	new_line[len + 1] = 0;
	free(line);
	return (new_line);
}

int	variable_length(char *line, int i)
{
	int		len_space;
	int		len_$;
	int		len_end;
	char	*pointer_space;
	char	*pointer_$;

	len_end = (int)ft_strlen(&line[i]);
	pointer_space = ft_memchr(&line[i], ' ', len_end);
	if (pointer_space == 0)
		len_space = len_end;
	else
		len_space = (int)(pointer_space - &line[i]);
	pointer_$ = ft_memchr(&line[i], '$', len_end);
	if (pointer_$ == 0)
		len_$ = len_end;
	else
		len_$ = (int)(pointer_$ - &line[i]);
	if (len_$ < len_space)
		return (len_$);
	else
		return (len_space);
}

char	*expand_var(int *i, int *j, char *new_line, char *line)
{
	int		var_len;
	char	*variable;
	char	*var_value;
	int		k;

	var_len = variable_length(line, *i);
	variable = malloc(var_len + 1);
	ft_memcpy(variable, &line[*i], var_len);
	variable[var_len] = 0;
	*i = *i + var_len;
	var_value = getenv(variable);
	if (var_value != NULL)
	{
		k = -1;
		while (var_value[++k])
			new_line = append_char(new_line, var_value[k]);
		*j += (int)ft_strlen(var_value);
	}
	return (new_line);
}

char	*expand_variables(char *line, char *envp[])
{
	char	*new_line;
	int		i;
	int		j;
	char	quote;

	quote = '0';
	new_line = NULL;
	if (ft_strchr((const char *)line, '$') == NULL)
		new_line = ft_strdup((const char *)line);
	else
	{
		i = 0;
		j = 0;
		new_line = malloc(ft_strlen(line));
		*new_line = 0;
		while (line[i])
		{
			if (line[i] == '"')
			{
				if (quote == '0')
					quote = '"';
				else if (quote == '"')
					quote = '0';
			}
			else if (line[i] == '\'')
			{
				if (quote == '0')
					quote = '\'';
				else if (quote == '\'')
					quote = '0';
			}
			else if (line[i] == '$')
			{
				i++;
				if (quote == '"' || quote == '0')
					new_line = expand_var(&i, &j, new_line, line);
				continue ;
			}
			else
				new_line = append_char(new_line, line[i]);
			i++;
			j++;
		}
	}
	free(line);
	return (new_line);
}
