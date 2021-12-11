/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:54:46 by sbienias          #+#    #+#             */
/*   Updated: 2021/12/11 20:54:58 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == 0)
	{
		if (access(filename, R_OK))
		{
			write(2, "Failed to open ", 15);
			write(2, filename, ft_strlen(filename));
			write(2, ": No such file or directory\n", 28);
			exit(1);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

char	**find_path(char **envp)
{
	int		i;
	char	**result;
	char	*tmp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 4) != 0)
		i++;
	result = ft_split(envp[i] + 5, ':');
	i = 0;
	while (result[i])
	{
		tmp = ft_strjoin(result[i], "/");
		free(result[i]);
		result[i] = tmp;
		i++;
	}
	return (result);
}
