/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:58:36 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/03 16:30:14 by sbienias         ###   ########.fr       */
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

int	main(int argc, char **argv, char *envp[])
{
	char	*prompt;
	char	*line;
	t_data	parsed;
	pid_t	pid;
	int		wstatus;
	int		i;
	struct termios	standard;
	int saved_stdin;
	int saved_stdout;
//	int		j;

//	set_term_vars(&standard);
	i = -1;
	initvals(&parsed, 0);
	parsed.envp = copyvar(envp);
	while (1)
	{
		catch_signal(SIGINT, handle_signal);
		saved_stdin = dup(0);
		saved_stdout = dup(1);
		prompt = get_prompt();
		line = readline((const char *) prompt);
		if (!line)
			exit(0);
		add_history(line);
		line = expand_variables(line, parsed.envp);
		parse(&parsed, line);
//		printf("srcin: %d, srcout: %d, pipes: %d, namein: %s, nameout: %s, "
//			   "limiter: %s, \n", parsed.srcin, parsed.srcout, parsed.pipes,
//			   parsed.namein, parsed.nameout, parsed.limiter);
//		j = -1;
//		while (parsed.commands[++j] != 0)
//			printf("command %d: %s\n", j, parsed.commands[j]);
//		pid = fork();
//		if (pid == -1)
//			return (1);
//		if (!pid)
		execute_line(&parsed);
		if (parsed.srcin)
			dup2(saved_stdin, 0);
//		if (parsed.srcout)
		dup2(saved_stdout, 1);
		close(saved_stdin);
		close(saved_stdout);
//			execute_line(parsed, envp);
//		else
//		{
//			wait(&wstatus);
//			if (WEXITSTATUS(wstatus) == 2)
//			{
//				free(prompt);
//				free(line);
//				return (0);
//			}
//		}
		free(prompt);
		free(line);
		initvals(&parsed, 1);
	}
//	tcsetattr(0, TCSANOW, &standard);
	return (0);
}
