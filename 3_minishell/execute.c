/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:08 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/04/04 18:06:29 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(char **cmd_split, t_data *data)
{
	char	*full_path;
	int		i;

	i = -1;
	execve(cmd_split[0], cmd_split, data->envp);
	if (data->paths != NULL)
	{
		while (data->paths[++i])
		{
			data->paths[i] = append_char(data->paths[i], '/');
			full_path = ft_strjoin(data->paths[i], cmd_split[0]);
			execve(full_path, cmd_split, data->envp);
			free(full_path);
		}
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd_split[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_arr(cmd_split);
	exit(127);
}

int	execute_built_in(t_data *data, int index)
{
	if (ft_memcmp(data->commands[index][0], "pwd\0", 4) == 0)
		return (data->exit_status = ft_pwd(data->commands[index]));
	else if (ft_memcmp(data->commands[index][0], "env\0", 4) == 0)
	{
		ft_env(*data);
		return (data->exit_status = 0);
	}
	else if (ft_memcmp(data->commands[index][0], "unset\0", 6) == 0)
	{
		ft_unset(*data, data->commands[index]);
		return (data->exit_status = 0);
	}
	else if (ft_memcmp(data->commands[index][0], "cd\0", 3) == 0)
		return (data->exit_status = ft_cd(data->commands[index], *data));
	else if (!ft_memcmp(data->commands[index][0], "echo\0", 5))
		return (data->exit_status = ft_echo(data->commands[index]));
	else if (!ft_memcmp(data->commands[index][0], "exit\0", 5))
		ft_exit(data, index);
	else if (!ft_memcmp(data->commands[index][0], "export\0", 7))
	{
		ft_export(data, data->commands[index]);
		return (data->exit_status = 0);
	}
	return (-1);
}

void	execute_single_command(t_data *data)
{
	pid_t	pid;
	int		wstatus;

	if (data->commands[0][0] == 0)
	{
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			exec_command(data->commands[0], data);
		wait(&wstatus);
		data->exit_status = WEXITSTATUS(wstatus);
		return ;
	}
	else if (execute_built_in(data, 0) == -1)
	{
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (!pid)
			exec_command(data->commands[0], data);
		wait(&wstatus);
		data->exit_status = WEXITSTATUS(wstatus);
	}
}

void	execute_pipes(int *fd, t_data *data)
{
	pid_t	pid;
	int		wstatus;

	if (pipe(fd) == -1)
		perror("pipe error");
	pid = fork();
	if (pid == -1)
		perror("fork error");
	if (!pid)
		pipe_first_command(fd, data);
	else
	{
		wait(&wstatus);
		data->exit_status = WEXITSTATUS(wstatus);
		handle_pipes(fd, data);
	}
}

void	execute_line(t_data *data)
{
	int		fd[2];
	int		ret_val;

	if (data->srcin == 2)
	{
		ret_val = ft_here_doc(*data);
		if (ret_val == -1)
			return ;
		data->here_doc_fd = open("temp_file123", 0, 0666);
		unlink("temp_file123");
		dup2(data->here_doc_fd, 0);
	}
	if (arr_length(data->commands) == 1)
	{
		redirect_output(*data);
		if (data->srcin == 1)
		{
			if (redirect_input(*data))
				return ;
		}
		execute_single_command(data);
	}
	else
		execute_pipes(fd, data);
}
