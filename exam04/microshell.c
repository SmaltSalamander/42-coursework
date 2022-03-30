/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:12:00 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 12:54:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	int	counter;
	int	endofseries;
	int	pipes;
	int	fds[2];

	endofseries = 0;
	counter = 1;
	if (argc == 1)
		return (1);
	while (counter < argc)
	{
		if (argv[counter] && strncmp(argv[counter], "|\0", 2) && strncmp(argv[counter], ";\0", 2))
			endofseries++;
		else if (endofseries)
		{
			if (strncmp(argv[counter], "|\0", 2) == 0)
				pipes = 1;
			else
				pipes = 0;
			argv[counter] = NULL;
			if (strncmp(argv[counter - endofseries], "cd\0", 3) == 0)
				execute_cd();
			else
			{
				if (pipes)
				{
					if (pipe(fds) == -1)
						fail();
				}
			}
		}
		
	}
}
