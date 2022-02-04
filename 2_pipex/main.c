/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:12:30 by sbienias          #+#    #+#             */
/*   Updated: 2021/12/16 11:19:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Cycle through possible paths, trying to access the command. If it works
//execute it, if it can't be found, free and exit
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

//Pipe for each process, with parent waiting for the child, with the read end
//open, closing the pipe after the child is done.
// Fork 0 is child, 1 is parent
void	handle_process(char **cmd, char **envp)
{
	int		status;
	int		ends[2];
	pid_t	pid;

	ft_pipe_error_check(pipe(ends));
	pid = fork();
	status = 0;
	if (pid < 0)
		error_message_exit("Fork failed", 1);
	else if (pid == 0)
	{
		close(ends[0]);
		dup2(ends[1], 1);
		execute_command(cmd[0], envp);
		exit(127);
	}
	else
	{
		dup2(ends[0], 0);
		waitpid(pid, &status, WNOHANG);
		if (status == 1)
			exit(1);
		close(ends[1]);
	}
}

// Call the handle_process command for each command in the program
void	pipex(char **commands, char **envp, int argc)
{
	int		cmdcount;

	cmdcount = 1;
	while (cmdcount < argc - 3)
	{
		cmdcount++;
		handle_process(commands + cmdcount, envp);
	}
}

// < file1 cmd1 | cmd2 > file2
int	main(int argc, char **argv, char **envp)
{
	int		fds[2];

	if (argc < 5)
		return (1);
	fds[0] = openfile(argv[1], 0);
	fds[1] = openfile(argv[argc - 1], 1);
	dup2(fds[0], 0);
	dup2(fds[1], 1);
	close(fds[0]);
	close(fds[1]);
	envp = find_path(envp);
	pipex(argv, envp, argc);
	execute_command(argv[argc - 2], envp);
	return (0);
}
