/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:45 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/25 13:57:06 by sbienias         ###   ########.fr       */
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
	result -= time;
	return (result);
}

void	print_request(t_philo *phil, int type)
{
	long	time;

	pthread_mutex_lock(phil->printflag);
	time = format_time(*phil->time);
	if (*phil->death)
	{
		pthread_mutex_unlock(phil->printflag);
		return ;
	}
	if (type == 0)
		printf("%ld Philosopher %d is eating\n", time, phil->nbr);
	else if (type == 1)
		printf("%ld Philosopher %d is sleeping\n", time, phil->nbr);
	else if (type == 2)
	{
		printf("%ld Philosopher %d died\n", time, phil->nbr);
		*phil->death = 1;
	}
	else if (type == 3)
		printf("%ld Philosopher %d is thinking\n", time, phil->nbr);
	else if (type == 4)
		printf("%ld Philosopher %d has taken a fork\n", time, phil->nbr);
	pthread_mutex_unlock(phil->printflag);
}

int	has_starved(t_philo	*phil)
{
	long	timenow;
	int		status;

	timenow = format_time(*phil->time);
	//printf("Philo %d Last meal %ld Timer %ld Time %ld\n", phil->nbr, phil->lastmeal, phil->timerdeath / 1000, timenow);
	pthread_mutex_lock(&(*phil->dead));
	status = 0;
	if (*phil->death)
		status = 1;
	if (!*phil->death && ((timenow - phil->lastmeal) >= phil->timerdeath / 1000))
	{
		print_request(phil, 2);
		status = 1;
	}
	pthread_mutex_unlock(&(*phil->dead));
	return (status);
}

void	switch_forks(t_philo	*phil, int type)
{
	if (type == 0)
	{
		pthread_mutex_lock(&(*phil->forknext));
		pthread_mutex_lock(&phil->forkmut);
	}
	else
	{
		pthread_mutex_unlock(&(*phil->forknext));
		pthread_mutex_unlock(&phil->forkmut);
	}
}

void	try_eating(t_philo	*phil, int *state)
{
	pthread_mutex_lock(&(*phil->dead));
	if (*phil->death)
	{
		pthread_mutex_unlock(&(*phil->dead));
		return ;
	}
	pthread_mutex_unlock(&(*phil->dead));
	if (!*phil->death && *state == 0)
	{
		pthread_mutex_lock(&(*phil->access));
		if (!phil->fork && !*phil->forkl)
		{
			pthread_mutex_unlock(&(*phil->access));
			return ;
		}
		phil->fork = 0;
		*phil->forkl = 0;
		pthread_mutex_unlock(&(*phil->access));
		if (phil->nbr % 2 == 0)
		{
			pthread_mutex_lock(&(*phil->forknext));
			pthread_mutex_lock(&phil->forkmut);
			//switch_forks(phil, 0);
		}
		else
		{
			pthread_mutex_lock(&phil->forkmut);
			pthread_mutex_lock(&(*phil->forknext));
		}
		print_request(phil, 4);
		print_request(phil, 4);
		phil->lastmeal = format_time(*phil->time);
		print_request(phil, 0);
		usleep(phil->timerfood);
		pthread_mutex_lock(&(*phil->access));
		phil->fork = 1;
		*phil->forkl = 1;
		pthread_mutex_unlock(&(*phil->access));
		if (phil->nbr % 2 == 0)
			switch_forks(phil, 1);
		else
		{
			pthread_mutex_unlock(&phil->forkmut);
			pthread_mutex_unlock(&(*phil->forknext));
		}
		phil->neededmeals -= 1;
		*state = 1;
	}
}

void	check_death(t_philo *phil, long time)
{
	long	timenow;
	long	timediff;

	timenow = format_time(*phil->time);
	timediff = timenow + time / 1000 - phil->lastmeal;
	if (timediff >= phil->timerdeath / 1000)
	{
		usleep((phil->timerdeath - timediff) * 1000 - 30);
		pthread_mutex_lock(&(*phil->dead));
		*phil->death = 1;
		pthread_mutex_unlock(&(*phil->dead));
		return ;
	}
}

void	sleep_time(t_philo	*phil, int *state)
{
	if (has_starved(phil))
		return ;
	if (*state == 1)
	{
		print_request(phil, 1);
		check_death(phil, phil->timersleep);
		//usleep(phil->timersleep);
		*state = 2;
	}
}

void	*active_phils(void *arg)
{
	t_philo	*phil;
	int		state;

	state = 0;
	phil = ((t_philo *) arg);
	while (phil->neededmeals && !has_starved(phil))
	{
		if (state == 2)
		{
			print_request(phil, 3);
			state = 0;
		}
		try_eating(phil, &state);
		sleep_time(phil, &state);
	}
	pthread_exit(NULL);
	return (NULL);
}

void	set_timers(t_philo *phil, char **argv)
{
	phil->timerdeath = ft_atoi(argv[2]) * 1000;
	phil->timerfood = ft_atoi(argv[3]) * 1000;
	phil->timersleep = ft_atoi(argv[4]) * 1000;
}

int	handle_one_philo(char **argv)
{
	printf("%d Philosopher 1 died\n", ft_atoi(argv[2]));
	return (1);
}

//Initialization of all shared mutexes, values, setting them for each philo and
//then running them
int	init_phils(t_philo *phils, int argc, char **argv)
{
	int				counter;
	int				number;
	int				*death;
	long			*time;
	pthread_mutex_t	*access;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*printflag;

	counter = 0;
	number = ft_atoi(argv[1]);
	if (number == 1)
		return (handle_one_philo(argv));
	access = malloc(sizeof(pthread_mutex_t));
	dead = malloc(sizeof(pthread_mutex_t));
	time = malloc(sizeof(long));
	death = malloc(sizeof(int));
	printflag = malloc(sizeof(pthread_mutex_t));
	*death = 0;
	*time = format_time(0);
	pthread_mutex_init(access, NULL);
	pthread_mutex_init(dead, NULL);
	pthread_mutex_init(printflag, NULL);
	while (counter < number)
	{
		phils[counter].nbr = counter + 1;
		if (argc == 6)
			phils[counter].neededmeals = ft_atoi(argv[argc - 1]);
		else
			phils[counter].neededmeals = -1;
		phils[counter].fork = 1;
		phils[counter].death = death;
		phils[counter].access = access;
		phils[counter].dead = dead;
		phils[counter].printflag = printflag;
		phils[counter].lastmeal = 0;
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

void	cleanup_memory(t_philo *phils, int counter)
{
	pthread_mutex_destroy(phils[0].dead);
	pthread_mutex_destroy(phils[0].access);
	pthread_mutex_destroy(phils[0].dead);
	free(phils[0].death);
	free(phils[0].time);
	while (counter--)
	{
		pthread_mutex_destroy(&phils[counter].forkmut);
	}
}

void	monitor_phils(t_philo *phils, char **argv)
{
	int	number;

	number = ft_atoi(argv[1]);
	while (number--)
	{
		pthread_join(phils[number].id, NULL);
	}
	cleanup_memory(phils, ft_atoi(argv[1]));
}

int	main(int argc, char **argv)
{
	t_philo			*phils;
	int				status;

	status = check_args(argc, argv);
	if (status)
		return (status);
	phils = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	status = init_phils(phils, argc, argv);
	if (status)
		return (0);
	monitor_phils(phils, argv);
	//pthread_join(tid, NULL);
	return (0);
}
