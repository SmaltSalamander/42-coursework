/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:12:30 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/31 22:18:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"

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

void	execute_command(char **str, char **envp)
{
	char	*cmd;
	int		i;

	i = 0;
	while (envp[i])
	{
		cmd = ft_strjoin(envp[i], *str);
		ft_printf("%s\n", cmd);
		execve((char const *) cmd, (char *const *)(str + 1), envp);
		free(cmd);
		i++;
	}
	ft_putstr_fd("failed all\n", 1);
	return ;
}

// < file1 cmd1 | cmd2 > file2
int	main(int argc, char **argv, char **envp)
{
	// int		fd1;
	// int		fd2;
	char	**str;
	int		ends[2];
	pid_t	processid;

	if (argc < 2)
		return (1);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	str = ft_split(argv[2], ' ');
	envp = find_path(envp);
	pipe(ends);
	processid = fork();
	if (processid < 0)
	{
		perror("Fork failed");
		return (1);
	}
	if (processid == 0)
		execute_command(str, envp);
	else
		ft_putstr_fd("\ntest\n", 1);
	return (0);
}
