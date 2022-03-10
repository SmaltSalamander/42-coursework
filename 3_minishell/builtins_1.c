/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:26 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/16 15:43:28 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **cmd)
{
	int		flag;
	int		i;

	flag = 0;
	if (cmd[1] != NULL)
	{
		if (cmd[1][0] == '-')
		{
			if (ft_strlen(cmd[1]) == 2 && cmd[1][1] == 'n')
				flag = 1;
		}
		if (flag == 0)
			i = 0;
		else
			i = 1;
		while (cmd[++i])
		{
			write(1, cmd[i], ft_strlen(cmd[i]));
			if (cmd[i + 1])
				write(1, " ", 1);
		}
	}
	if (!flag)
		write(1, "\n", 1);
	return (0);
}

int	ft_cd(char **line_split, t_data data)
{
	int	err;

	if (line_split[1] == NULL)
		err = chdir(ft_getenv("HOME", data));
	else
	{
		if (!ft_strncmp(line_split[1], "~", 2))
			err = chdir(ft_getenv("HOME", data));
		else
			err = chdir(line_split[1]);
	}
	if (err == -1)
	{
		dup2(2, 1);
		printf("minishell: cd: %s: No such file or directory\n", line_split[1]);
		return (1);
	}
	return (0);
}

int	ft_pwd(char **line_split)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (line_split[1] != NULL && line_split[1][0] == '-')
	{
		dup2(2, 1);
		printf("minishell: pwd: %s: invalid option\n", line_split[1]);
		return (2);
	}
	else
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	return (0);
}

int	ft_findalnum(char *str)
{
	int	i;

	i = -1;
	if (!ft_isalpha(str[0]))
		i = -2;
	while (str[++i] && i >= 0)
	{
		if (str[i] == '=')
			return (i);
		if (!ft_isalnum(str[i]))
			break ;
	}
	dup2(2, 1);
	printf("minishell: export: `%s': not a valid identifier\n", str);
	return (0);
}
// Need to implement check if value exists

void	ft_export(t_data *data, char **line)
{
	int		count;
	char	*cpy;
	int		len;

	count = 0;
	if (line[1])
	{
		len = ft_findalnum(line[1]);
		if (!len)
			return ;
		cpy = ft_strdup(line[1]);
		while (data->envp[count] != NULL)
		{
			if (!ft_memcmp(data->envp[count], line[1], len + 1))
			{
				free(data->envp[count]);
				data->envp[count] = cpy;
				return ;
			}
			count++;
		}
		data->envp = add_to_array(cpy, data->envp, &count);
	}
}
