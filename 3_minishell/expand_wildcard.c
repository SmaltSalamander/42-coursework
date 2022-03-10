/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:31:18 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/03/10 13:57:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	matched_non_star(int *i, char **pattern, char **sub_pattern, char **entry)
{
	if (pattern[0][i[0]] != '*')
	{
		*sub_pattern = append_char(*sub_pattern, pattern[0][i[0]]);
		if (!pattern[0][i[0] + 1])
		{
			if (ft_strlen(sub_pattern[0]) > ft_strlen(entry[0] + i[1])
				|| !ft_strnstr(entry[0] + i[1], sub_pattern[0],
					ft_strlen(entry[0] + i[1])))
				return (0);
			else
				return (1);
		}
	}
	return (2);
}

int	matched_star(int *i, char **pattern, char **sub_pattern, char **entry)
{
	char	*found_pos;

	if (pattern[0][i[0]] == '*' && i[0] != 0)
	{
		found_pos = ft_strnstr(entry[0] + i[1], sub_pattern[0],
				ft_strlen(entry[0] + i[1]));
		if (!found_pos)
			return (0);
		else
		{
			i[1] = (int)(found_pos - entry[0]) + (int)ft_strlen(sub_pattern[0]);
			free(sub_pattern[0]);
			sub_pattern[0] = ft_calloc(1, 1);
		}
	}
	return (2);
}

int	matched(char *pattern, char *entry)
{
	int		i[2];
	char	*sub_pattern;
	int		ret;

	i[1] = 0;
	i[0] = -1;
	while (pattern[++i[0]])
	{
		if (pattern[i[0]] == '*')
			break ;
		i[1]++;
		if (pattern[i[0]] != entry[i[0]])
			return (0);
	}
	sub_pattern = ft_calloc(1, 1);
	while (pattern[++i[0]])
	{
		ret = matched_non_star(i, &pattern, &sub_pattern, &entry);
		if (ret != 2)
		{
			free(sub_pattern);
			return (ret);
		}
		ret = matched_star(i, &pattern, &sub_pattern, &entry);
		if (ret != 2)
		{
			free(sub_pattern);
			return (ret);
		}
	}
	return (1);
}

int	check_pattern_all(char *pattern, int pattern_all)
{
	int	k;

	pattern_all = 1;
	k = -1;
	while (pattern[++k])
	{
		if (pattern[k] != '*')
		{
			pattern_all = 0;
			break ;
		}
	}
	return (pattern_all);
}

char	*expand_wildcard(int *i, char *new_line, char *line)
{
	DIR				*current_dir;
	struct dirent	*entry;
	char			*pattern;
	int				pattern_all;
	char			*tmp_str;

	pattern_all = 1;
	pattern = extract_pattern(i, line, new_line);
	pattern_all = check_pattern_all(pattern, pattern_all);
	current_dir = opendir(".");
	while (1)
	{
		entry = readdir(current_dir);
		if (!entry)
			break ;
		if ((pattern_all && entry->d_name[0] != '.')
			|| (!pattern_all && matched(pattern, entry->d_name)))
		{
			tmp_str = ft_strjoin(new_line, entry->d_name);
			free(new_line);
			tmp_str = append_char(tmp_str, ' ');
			i[1] = (int) ft_strlen(tmp_str);
			new_line = tmp_str;
		}
	}
	free(pattern);
	closedir(current_dir);
	return (new_line);
}
