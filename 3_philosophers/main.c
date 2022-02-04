/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:45 by sbienias          #+#    #+#             */
/*   Updated: 2021/12/21 22:10:24 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher(void *vargp)
{
	printf("here");
	printf("Philosopher here, %p\n", vargp);
	return (vargp);
}

int	main(int argc, char **argv)
{
	pthread_t	tid;
	int			phil_num;
	void		*str;

	str = malloc(4);
	if (argc < 2)
		return (1);
	phil_num = ft_atoi(argv[1]);
	while (phil_num-- >= 0)
		pthread_create(&tid, NULL, philosopher, str);
	//pthread_join(tid, NULL);
	pthread_exit(NULL);
	return (0);
}