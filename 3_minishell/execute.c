/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:08 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/03 12:39:07 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_data_tmp(t_data *data)
{
	data->commands = malloc(sizeof(char *) *3);
	data->commands[0] = "cat";
	data->commands[1] = "grep test";
	data->commands[2] = 0;
	data->srcin = 1;
	data->srcout = 0;
	data->pipes = 1;
	data->flags = 0;
	data->nameout = "test1";
	data->namein = "test";
	data->limiter = "end";
}

void	redirect_input(t_data data)
{
	int	fd_file_in;

	if (data.srcin != 0)
	{
		if (!access(data.namein, F_OK))
		{
			fd_file_in = open(data.namein, 0, 0666);
			if (fd_file_in == -1)
				perror(data.namein);
			else
			{
				dup2(fd_file_in, 0);
				close(fd_file_in);
			}
		}
		else
			perror(data.namein);
	}
}

void	redirect_output(t_data data)
{
	int	fd_file_out;

	if (data.srcout != 0)
	{
		fd_file_out = open_file_write(data.nameout);
		if (fd_file_out == -1)
			perror(data.namein);
		else
		{
			dup2(fd_file_out, 1);
			close(fd_file_out);
		}
	}
}

void	exec_command(char **cmd_split, char **paths, char *envp[])
{
	char	*full_path;
	int		i;

	i = -1;
	execve(cmd_split[0], cmd_split, envp);
	while (paths[++i])
	{
		paths[i] = append_char(paths[i], '/');
		full_path = ft_strjoin(paths[i], cmd_split[0]);
//		dprintf(2, "path: %s\n", full_path);
		execve(full_path, cmd_split, envp);
		free(full_path);
	}
	free_arr(cmd_split);
	exit(0);
//	perror(cmd_split[0]);
}

//void	execute_single_command(t_data data, char *line, char **envp)
void	execute_single_command(t_data *data, char *line)
{
	char	**cmd_split;
	pid_t	pid;

	cmd_split = ft_split(line, ' ');
	if (cmd_split[0] == 0)
	{
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			exec_command(cmd_split, data->paths, data->envp);
		wait(0);
		return ;
	}
	else if (ft_memcmp(cmd_split[0], "pwd\0", 4) == 0)
		ft_pwd(cmd_split, data->envp);
	else if (ft_memcmp(cmd_split[0], "env\0", 4) == 0)
		ft_env(*data);
	else if (ft_memcmp(cmd_split[0], "unset\0", 6) == 0)
		ft_unset(*data, cmd_split);
	else if (ft_memcmp(cmd_split[0], "cd\0", 3) == 0)
		ft_cd(cmd_split, *data);
	else if (!ft_memcmp(cmd_split[0], "echo\0", 5))
		ft_echo(cmd_split, line);
	else if (!ft_memcmp(cmd_split[0], "exit\0", 5))
		ft_exit(cmd_split);
	else if (!ft_memcmp(cmd_split[0], "export\0", 7))
		ft_export(data, cmd_split);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			exec_command(cmd_split, data->paths, data->envp);
		wait(0);
	}
	free_arr(cmd_split);
//	exit(0);
}

void	multi_pipe_child(int i, int *fd, int (*new_fd)[2], t_data data)
{
	char	**cmd_split;

	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	close(new_fd[i % 2][0]);
	dup2(new_fd[i % 2][1], 1);
	close(new_fd[i % 2][1]);
	cmd_split = ft_split(data.commands[i], ' ');
	exec_command(cmd_split, data.paths, data.envp);
}

/*
 * O_WRONLY|O_CREAT == 65
 * O_RDONLY == 0
 * O_WRONLY|O_TRUNC == 513
 * https://reverseengineering.stackexchange.com/questions/19352/
 * how-to-get-meaning-of-flags-by-integer
 */
//
//void	handle_output(int i, int *fd, t_data data)
//{
//	char	**cmd_split;
//	pid_t	pid;
//
//	dup2(fd[0], 0);
//	close(fd[1]);
//	redirect_output(data);
//	cmd_split = ft_split(data.commands[i], ' ');
//	pid = fork();
//	if (pid == -1)
//		perror("fork error");
//	if (!pid)
//		exec_command(cmd_split, data.paths, data.envp);
//	free_arr(cmd_split);
//}

void	pipe_last_command(int i, int *fd, t_data data)
{
	char	**cmd_split;
	int		fd_file;
	pid_t	pid;

	dup2(fd[0], 0);
	close(fd[1]);
//	dprintf(2, "%s\n", data.commands[i]);
	cmd_split = ft_split(data.commands[i], ' ');
	if (data.srcout)
	{
		if (access(data.nameout, F_OK))
			fd_file = open(data.nameout, 65, 0666);
		else
			fd_file = open(data.nameout, 513, 0666);
		dup2(fd_file, 1);
		close(fd_file);
	}
	pid = fork();
	if (pid == -1)
		perror("fork error");
	if (!pid)
		exec_command(cmd_split, data.paths, data.envp);
//	dprintf(2, "test_before\n");
	wait(0);
//	dprintf(2, "test_after\n");
	free_arr(cmd_split);
//	free_arr(par.paths);
}

void	handle_pipes(int *fd, t_data data)
{
	pid_t	pid;
	int		i;
	int		new_fd[2][2];

	i = 0;
	while (++i < data.pipes)
	{
		wait(0);
		if (pipe(new_fd[i % 2]) == -1)
			perror("pipe error");
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			multi_pipe_child(i, fd, new_fd, data);
		else
		{
//			wait(0);
			close(fd[0]);
			close(fd[1]);
			fd = new_fd[i % 2];
		}
	}
	pipe_last_command(i, fd, data);
}

//void	pipe_first_command(int *fd, t_data data)
//{}
void	pipe_first_command(int *fd, t_data data)
{
//	pid_t pid;
	int fd_file;
	char **cmd_split;

	dup2(fd[1], 1);
	close(fd[0]);
	if (data.srcin)
	{
		if (data.srcin == 2)
		{
			fd_file = open("temp_file123", 0, 0666);
			unlink("temp_file123");
		}
		else
		{
			if (!access(data.namein, F_OK))
				fd_file = open(data.namein, 0, 0666);
			else
			{
				perror(data.namein);
				return;
			}
		}
		dup2(fd_file, 0);
		close(fd_file);
	}
//	pid = fork();
//	if (pid == -1)
//		perror("fork error");
	cmd_split = ft_split(data.commands[0], ' ');
//	if (!pid)
	exec_command(cmd_split, data.paths, data.envp);
//	wait(0);
	free_arr(cmd_split);
}

void	execute_line(t_data *data)
//void	execute_line(t_data data, char **envp)
{
	int	fd[2];
	pid_t	pid;
	int		ret_val;

//	initialize_data_tmp(&data);
//	printf("%d, %d, %d, %d, %s, %s, %s\n", data.srcin, data.srcout, data.pipes, data.here_doc_fd, data.namein, data.nameout, data.commands[0]);
	if (data->srcin == 2)
	{
		ret_val = ft_here_doc(*data);
		if (ret_val == -1)
			return ;
		data->here_doc_fd = open("temp_file123", 0, 0666);
		unlink("temp_file123");
		dup2(data->here_doc_fd, 0);
	}
	else
		redirect_input(*data);
	if (arr_length(data->commands) == 1)
	{
		redirect_output(*data);
		execute_single_command(data, data->commands[0]);
//		execute_single_command(data, data.commands[0], envp);
	}
	else
	{
		if (pipe(fd) == -1)
			perror("pipe error");
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			pipe_first_command(fd, *data);
		else
		{
			wait(0);
			handle_pipes(fd, *data);
		}
	}
}
