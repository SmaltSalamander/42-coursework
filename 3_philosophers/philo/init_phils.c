/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:06:18 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/10 13:35:02 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	**init_mutexes(void)
{
	pthread_mutex_t	*access;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*printflag;
	pthread_mutex_t	**mutexarr;

	access = malloc(sizeof(pthread_mutex_t));
	if (!access)
		return (NULL);
	mutexarr = malloc(sizeof(pthread_mutex_t) * 3);
	if (!mutexarr)
		return (NULL);
	dead = malloc(sizeof(pthread_mutex_t));
	if (!dead)
		return (NULL);
	printflag = malloc(sizeof(pthread_mutex_t));
	if (!printflag)
		return (NULL);
	pthread_mutex_init(access, NULL);
	pthread_mutex_init(dead, NULL);
	pthread_mutex_init(printflag, NULL);
	mutexarr[0] = access;
	mutexarr[1] = dead;
	mutexarr[2] = printflag;
	return (mutexarr);
}

static void	set_numbers(t_philo	*phils, char **argv, int argc)
{
	int	counter;
	int	num;

	counter = 0;
	num = ft_atoi(argv[1]);
	while (counter < num)
	{
		if (argc == 6)
			phils[counter].neededmeals = ft_atoi(argv[argc - 1]);
		else
			phils[counter].neededmeals = -1;
		phils[counter].nbr = counter + 1;
		phils[counter].fork = 1;
		phils[counter].lastmeal = 0;
		phils[counter].totalcount = num;
		set_timers(&phils[counter], argv);
		counter++;
	}
}

void	set_shared_values(t_philo	*phils, pthread_mutex_t **mutexarr, int num)
{
	int	*death;
	int	counter;

	death = malloc(sizeof(int));
	*death = 0;
	counter = 0;
	while (counter < num)
	{
		phils[counter].death = death;
		phils[counter].access = mutexarr[0];
		phils[counter].dead = mutexarr[1];
		phils[counter].printflag = mutexarr[2];
		pthread_mutex_init(&phils[counter].forkmut, NULL);
		if (counter != 0)
		{
			phils[counter].forknext = &(phils[counter - 1].forkmut);
			phils[counter].forkl = &(phils[counter - 1].fork);
		}
		counter++;
	}
	phils[0].forknext = &(phils[num - 1].forkmut);
	phils[0].forkl = &(phils[num - 1].fork);
}

int	run_philosophers(t_philo *phils, int number)
{
	long	*time;
	int		counter;

	time = malloc(sizeof(long));
	*time = format_time(0);
	counter = -1;
	while (++counter < number)
	{
		phils[counter].time = time;
		if (pthread_create(&phils[counter].id, NULL, active_phils, \
		&phils[counter]))
		{
			printf("Thread creation error detected\n");
			return (2);
		}
	}
	return (0);
}

//Initialization of all shared mutexes, values, setting them for each philo and
//then running them
int	init_phils(t_philo *phils, int argc, char **argv)
{
	int				status;
	int				number;
	pthread_mutex_t	**mutexarr;

	number = ft_atoi(argv[1]);
	if (number == 1)
		return (handle_one_philo(argv));
	mutexarr = init_mutexes();
	if (!mutexarr)
		return (-1);
	set_numbers(phils, argv, argc);
	set_shared_values(phils, mutexarr, number);
	free(mutexarr);
	status = run_philosophers(phils, number);
	return (status);
}
