/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:49:03 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/14 12:47:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_data data, char **line_split)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line_split[1]);
	while (data.envp[i] != NULL)
	{
		if (!ft_memcmp(data.envp[i], line_split[1], len))
		{
			free(data.envp[i]);
			while (data.envp[i + 1] != NULL)
			{
				data.envp[i] = data.envp[i + 1];
				i++;
			}
			data.envp[i] = data.envp[i + 1];
			return ;
		}
		i++;
	}
}

void	ft_env(t_data data)
{
	int	count;

	count = 0;
	while (data.envp[count] != NULL)
	{
		printf("%s\n", data.envp[count]);
		count++;
	}
}

void	ft_exit(t_data *data, int index)
{
	int	status;
	int	i;

	if (data->commands[index][1])
	{
		i = 0;
		while (data->commands[index][1][i])
		{
			if (!ft_isdigit(data->commands[index][1][i++]))
				exit(2);
		}
		status = ft_atoi(data->commands[index][1]);
		clean_exit(data, status, 1);
	}
	clean_exit(data, 0, 1);
}
