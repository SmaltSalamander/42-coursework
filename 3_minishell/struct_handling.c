/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:09:23 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/16 16:18:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr_arr(char ***arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free_arr(arr[i]);
	free(arr);
}

void	initvals(t_data *parsed, int type)
{
	parsed->srcin = 0;
	parsed->srcout = 0;
	parsed->pipes = 0;
	if (type && parsed->commands)
		free_arr_arr(parsed->commands);
	parsed->commands = NULL;
	if (type && parsed->nameout)
		free(parsed->nameout);
	parsed->nameout = NULL;
	if (type && parsed->namein)
		free(parsed->namein);
	parsed->namein = NULL;
	parsed->limiter = NULL;
	if (type == 0)
		parsed->exit_status = 0;
	parsed->here_doc_fd = -1;
	parsed->count = 0;
	parsed->quote = 1;
	parsed->srcerr = 0;
	parsed->nameerr = NULL;
	parsed->paths = ft_split(ft_getenv("PATH", *parsed), ':');
}

char	*ft_getenv(const char *name, t_data data)
{
	char	**env;
	int		counter;
	int		len;

	env = data.envp;
	counter = 0;
	len = (int)ft_strlen(name);
	while (env[counter])
	{
		if (!ft_memcmp(env[counter], name, len))
		{
			return (env[counter] + len + 1);
		}
		counter++;
	}
	return (NULL);
}

void	add_element(char **tmp, char ***arr, int	*count, int type)
{
	if (**tmp)
		*arr = add_to_array(*tmp, *arr, count);
	else
		free(*tmp);
	if (type > 0)
		*tmp = ft_calloc(1, 1);
}
