/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:45 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/22 16:22:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	return (0);
}

long	format_time(long time)
{
	struct timeval	timetoconvert;
	long			result;

	gettimeofday(&timetoconvert, NULL);
	result = timetoconvert.tv_sec * 1000;
	result += timetoconvert.tv_usec / 1000;
	if (time)
	{
		result -= time;
	}
	return (result);
}

void	print_request(t_philo phil, int type)
{
	long	time;

	time = format_time(*phil.time);
	// if (type == 2)
	// 	printf("%ld Philosopher %d died\n", time, phil.nbr);
	if (type == 0)
		printf("%ld Philosopher %d is eating\n", time, phil.nbr);
	else if (type == 1)
		printf("%ld Philosopher %d is sleeping\n", time, phil.nbr);
	else if (type == 2)
		printf("%ld Philosopher %d died\n", time, phil.nbr);
	else if (type == 3)
		printf("%ld Philosopher %d is thinking\n", time, phil.nbr);
	else if (type == 4)
		printf("%ld Philosopher %d has taken a fork\n", time, phil.nbr);
}

int		has_starved(t_philo	*phil)
{
	// long	timesincemeal;

	// timesincemeal = phil->lastmeal - *phil->time;
	printf("Last meal %ld Timer %ld\n", phil->lastmeal, phil->timerdeath);
	// pthread_mutex_lock(&(*phil->dead));
	if (phil->death)
		return (1);
	if (!phil->death && phil->lastmeal >= phil->timerdeath)
	{
		phil->death = 1;
		return (1);
	}
	// else
	// 	pthread_mutex_lock(&(*phil->dead));
	return (0);
}

void	try_eating(t_philo	*phil, int *state)
{
	if (*state == 0 && phil->fork && *phil->forkl && !has_starved(phil))
	{
		phil->fork = 0;
		pthread_mutex_lock(&phil->forkmut);
		print_request(*phil, 4);
		*phil->forkl = 0;
		pthread_mutex_lock(&(*phil->forknext));
		print_request(*phil, 4);
		phil->lastmeal = format_time(*phil->time);
		print_request(*phil, 0);
		usleep(phil->timerfood);
		pthread_mutex_unlock(&phil->forkmut);
		pthread_mutex_unlock(&(*phil->forknext));
		phil->fork = 1;
		*phil->forkl = 1;
		phil->neededmeals -= 1;
		*state = 1;
	}
}

void	sleep_time(t_philo	*phil, int *state)
{
	if (*state == 1 && !has_starved(phil))
	{
		print_request(*phil, 1);
		usleep(phil->timersleep);
		*state = 2;
	}
}

void	*active_phils(void *arg)
{
	t_philo	*phil;
	int		state;

	state = 0;
	phil = ((t_philo *) arg);
	if (phil->nbr % 2 == 0)
		usleep(50);
	while (phil->neededmeals && !has_starved(phil))
	{
		if (state == 2)
		{
			print_request(*phil, 3);
			state = 0;
		}
		try_eating(phil, &state);
		sleep_time(phil, &state);
	}
	if (phil->death)
		print_request(*phil, 2);
	else
		printf("huh\n");
	pthread_exit(NULL);
	return (NULL);
}

// void	oversee(t_philo *phils, int num)
// {
	
// }
void	set_timers(t_philo *phil, char **argv)
{
	phil->timerdeath = ft_atoi(argv[2]);
	phil->timerfood = ft_atoi(argv[3]);
	phil->timersleep = ft_atoi(argv[4]);
}

int	init_phils(t_philo *phils, int argc, char **argv)
{
	int		counter;
	int		number;
	long	*time;
	pthread_mutex_t	*dead;

	counter = 0;
	dead = malloc(sizeof(pthread_mutex_t));
	time = malloc(sizeof(long));
	*time = format_time(0);
	number = ft_atoi(argv[1]);
	pthread_mutex_init(dead, NULL);
	while (counter < number)
	{
		phils[counter].nbr = counter + 1;
		if (argc == 6)
			phils[counter].neededmeals = ft_atoi(argv[argc - 1]);
		else
			phils[counter].neededmeals = -1;
		phils[counter].fork = 1;
		phils[counter].death = 0;
		phils[counter].dead = dead;
		set_timers(&phils[counter], argv);
		pthread_mutex_init(&phils[counter].forkmut, NULL);
		if (counter != 0)
		{
			phils[counter].forknext = &(phils[counter - 1].forkmut);
			phils[counter].forkl = &(phils[counter - 1].fork);
		}
		counter++;
	}
	phils[0].forknext = &(phils[number - 1].forkmut);
	phils[0].forkl = &(phils[number - 1].fork);
	counter = -1;
	while (++counter < number)
	{
		phils[counter].time = time;
		if (pthread_create(&phils[counter].id, NULL, active_phils, \
		&phils[counter]))
			return (printf("err\n"));
	}
	return (0);
}

void	monitor_phils(t_philo *phils, char **argv)
{
	int counter;
	int	number;
	// int	fed;

	counter = -1;
	number = ft_atoi(argv[1]);
	// while (++counter < number)
	// {
	// 	//*phils[counter].time = format_time(*phils[counter].time);
	// 	if (phils[counter].neededmeals == 0)
	// 		fed++;
	// 	if (fed == number)
	// 		break ;
	// 	if (phils[counter].death)
	// 		break ;
	// 	if (counter == number - 1)
	// 		counter = 0;
	// }
	while (++counter < number)
	{
		pthread_join(phils[counter].id, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_philo			*phils;
	int				status;

	status = check_args(argc, argv);
	if (status)
		return (status);
	phils = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	init_phils(phils, argc, argv);
	monitor_phils(phils, argv);
	//pthread_join(tid, NULL);
	pthread_exit(NULL);
	return (0);
}
