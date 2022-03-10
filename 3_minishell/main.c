/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:58:36 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/10 09:20:22 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(void)
{
	char	*cwd;
	char	*tmp;
	char	*prompt;
	char	**tmp_arr;
	int		i;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	tmp_arr = ft_split(cwd, '/');
	free(cwd);
	i = -1;
	while (tmp_arr[++i])
		;
	if (tmp_arr[0] == NULL)
		tmp = ft_strjoin("[minishell ", "/");
	else
		tmp = ft_strjoin("[minishell ", tmp_arr[i - 1]);
	prompt = ft_strjoin(tmp, "]$ ");
	free(tmp);
	free_arr(tmp_arr);
	return (prompt);
}

char	**copyvar(char	**envp)
{
	char	**ret;
	int		num;

	num = 0;
	while (envp[num] != NULL)
		num++;
	ret = malloc(sizeof(char *) * (num + 1));
	num = 0;
	while (envp[num] != NULL)
	{
		ret[num] = ft_strdup(envp[num]);
		num++;
	}
	ret[num] = 0;
	return (ret);
}

int	g_flag[2] = {1, 0};

void	prepare_exec_readline(int *saved_streams, char **line)
{
	char	*prompt;

	catch_signal(SIGINT, handle_signal);
	catch_signal(SIGQUIT, handle_signal);
	saved_streams[0] = dup(0);
	saved_streams[1] = dup(1);
	saved_streams[2] = dup(2);
	prompt = get_prompt();
	if (!(g_flag[0] && g_flag[1]))
	{
		g_flag[0] = 1;
		line[0] = readline((const char *) prompt);
	}
	else
	{
		g_flag[0] = 0;
		line[0] = readline("");
	}
	g_flag[1] = 0;
	free(prompt);
}

void	cleanup(int *saved_streams, char *line, t_data *parsed)
{
	dup2(saved_streams[0], 0);
	dup2(saved_streams[1], 1);
	dup2(saved_streams[2], 2);
	close(saved_streams[0]);
	close(saved_streams[1]);
	close(saved_streams[2]);
	free(line);
	if (parsed->paths != NULL)
		free_arr(parsed->paths);
	initvals(parsed, 1);
	if (!access("temp_file123", F_OK))
		unlink("temp_file123");
}

int	main(int argc, char **argv, char *envp[])
{
	char	*line;
	t_data	parsed;
	int		saved_streams[3];

	if (argc != 1 || argv[0] == 0)
		exit (1);
	parsed.envp = copyvar(envp);
	initvals(&parsed, 0);
	while (1)
	{
		prepare_exec_readline(saved_streams, &line);
		if (!line)
			clean_exit(&parsed, 0, 0);
		if (*line != 0)
		{
			add_history(line);
			line = expand_variables(line, &parsed);
			parse(&parsed, line);
			execute_line(&parsed);
			while (wait(0) != -1)
				;
		}
		cleanup(saved_streams, line, &parsed);
	}
}
