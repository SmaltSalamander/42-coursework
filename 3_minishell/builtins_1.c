/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:45:26 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/02 20:41:37 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **line_split, char *line)
{
	int		flag;
	int		line_len;

	line_len = (int)ft_strlen(line);
	flag = 0;
	if (line_split[1] != NULL)
	{
		if (line_split[1][0] == '-')
		{
			if (ft_strlen(line_split[1]) == 2 && line_split[1][1] == 'n')
				flag = 1;
		}
		if (flag == 0)
			printf("%s\n", line + 5);
		else
		{
			if (line_len > 8)
				printf("%s", line + 8);
		}
	}
}

void	ft_cd(char **line_split, t_data data)
{
	int	err;

	if (line_split[1] == NULL)
		err = chdir(getenv("HOME"));
	else
		err = chdir(line_split[1]);
	if (err == -1)
		printf("minishell: cd: %s: No such file or directory", line_split[1]);
}

void	ft_pwd(char **line_split, char *envp[])
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (line_split[1] != NULL && line_split[1][0] == '-')
	{
		printf("minishell: pwd: %s: invalid option\n", line_split[1]);
	}
	else
	{
		printf("%s\n", cwd);
		free(cwd);
	}
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
