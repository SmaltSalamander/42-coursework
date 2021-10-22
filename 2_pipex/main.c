/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:12:30 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/20 20:15:13 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
// < file1 cmd1 | cmd2 > file2
int main(int argc, char **argv)
{
	char	**str;
	if (argc < 5)
		return (1);
	str = ft_split(argv[2], ' ');
	execve((const char *) argv[2], (char * const*) argv[1], \
	(char * const*)*(str + 1));
	pipe();
	fork();
}
