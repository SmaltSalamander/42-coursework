/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:04:28 by aserdyuk          #+#    #+#             */
/*   Updated: 2021/12/22 20:04:42 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		arr_length(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	open_file_write(char *filename)
{
	if (access(filename, F_OK))
		return (open(filename, 65, 0666));
	else
		return (open(filename, 513, 0666));
}
