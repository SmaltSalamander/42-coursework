/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:12:30 by sbienias          #+#    #+#             */
/*   Updated: 2021/11/21 20:48:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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

void	execute_command(char *command, char **envp)
{
	char	*cmd;
	int		i;
	char	**str;

	i = 0;
	str = ft_split(command, ' ');
	while (envp[i])
	{
		cmd = ft_strjoin(envp[i], *str);
		if (access(cmd, F_OK) == 0)
			execve((char const *) cmd, (char *const *)(str), envp);
		free(cmd);
		i++;
	}
	write(2, "command not found", 17);
	i = 0;
	while (str[i])
		free(str[i++]);
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(str);
	free(envp);
	exit(-1);
}

// Fork 0 is child, 1 is parent
void	pipex(char **commands, char **envp, int argc)
{
	int		ends[2];
	pid_t	processid;
	int		cmdcount;
	int		status;

	pipe(ends);
	cmdcount = 1;
	processid = 1;
	while (++cmdcount < argc - 2 && processid)
		processid = fork();
	if (processid < 0)
	{
		write(2, "Fork failed", 11);
		return ;
	}
	else if (processid > 0)
	{
		close(ends[1]);
		dup2(ends[0], 0);
		if (wait(&status) != -1)
			execute_command(commands[argc - 2], envp);
	}
	else
	{
		close(ends[0]);
		dup2(ends[1], 1);
		execute_command(commands[cmdcount], envp);
	}
}

// < file1 cmd1 | cmd2 > file2
int	main(int argc, char **argv, char **envp)
{
	int		fds[2];

	if (argc < 4)
		return (1);
	fds[0] = openfile(argv[1], 0);
	fds[1] = openfile(argv[argc - 1], 1);
	dup2(fds[0], 0);
	dup2(fds[1], 1);
	close(fds[0]);
	close(fds[1]);
	envp = find_path(envp);
	pipex(argv, envp, argc);
	// execute_command(argv[argc - 2], envp);
	return (0);
}
