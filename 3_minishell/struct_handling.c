/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:09:23 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/03 16:29:28 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initvals(t_data *parsed, int type)
{
	parsed->srcin = 0;
	parsed->srcout = 0;
	parsed->pipes = 0;
	parsed->flags = 0;
	if (type && parsed->commands)
		free_arr(parsed->commands);
	parsed->commands = NULL;
	if (type && parsed->nameout)
		free(parsed->nameout);
	parsed->nameout = NULL;
	if (type && parsed->namein)
		free(parsed->namein);
	parsed->namein = NULL;
	parsed->limiter = NULL;
	if (type == 0)
		parsed->paths = ft_split(getenv("PATH"), ':');
	parsed->here_doc_fd = -1;
}

char	*ft_getenv(const char *name, t_data data)
{
	char	**env;
	int		counter;
	int		len;

	env = data.envp;
	counter = 0;
	len = ft_strlen(name);
	while (env[counter])
	{
		if (!ft_memcmp(env[counter], name, len))
		{
			return (env[counter] + len + 1);
		}
		counter++;
	}
}
