/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:12:30 by sbienias          #+#    #+#             */
/*   Updated: 2021/12/11 21:04:31 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	exit(1);
}

void	handle_process(pid_t pid, char **cmd, char **envp, int	*ends)
{
	int		status;

	status = 0;
	if (pid < 0)
	{
		write(2, "Fork failed", 11);
		return ;
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, WNOHANG);
		if (status == 1)
			exit(1);
		close(ends[1]);
		dup2(ends[0], 0);
		execute_command(cmd[3], envp);
	}
	else
	{
		close(ends[0]);
		dup2(ends[1], 1);
		execute_command(cmd[2], envp);
	}
}

// Fork 0 is child, 1 is parent
void	pipex(char **commands, char **envp, int argc)
{
	pid_t	processid;
	int		cmdcount;
	int		ends[2];

	pipe(ends);
	cmdcount = 1;
	processid = 1;
	while (cmdcount < argc - 3 && processid)
	{
		processid = fork();
		cmdcount++;
	}
	handle_process(processid, commands, envp, ends);
}

// < file1 cmd1 | cmd2 > file2
int	main(int argc, char **argv, char **envp)
{
	int		fds[2];

	if (argc != 5)
		return (1);
	fds[0] = openfile(argv[1], 0);
	fds[1] = openfile(argv[argc - 1], 1);
	dup2(fds[0], 0);
	dup2(fds[1], 1);
	close(fds[0]);
	close(fds[1]);
	envp = find_path(envp);
	pipex(argv, envp, argc);
	return (0);
}
