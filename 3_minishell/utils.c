/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:04:28 by aserdyuk          #+#    #+#             */
/*   Updated: 2021/12/22 20:04:42 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arr_length(char ***arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	open_file_write(char *filename, int mode)
{
	if (access(filename, F_OK))
		return (open(filename, 65, 0666));
	else
	{
		if (mode == 1)
			return (open(filename, 513, 0666));
		else if (mode == 2)
			return (open(filename, 1025, 0666));
	}
	return (-1);
}

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

void	clean_exit(t_data *data, int status, int flag)
{
	if (flag)
		free_arr_arr(data->commands);
	rl_clear_history();
	free_arr(data->envp);
	if (data->paths != NULL)
		free_arr(data->paths);
	exit(status);
}
