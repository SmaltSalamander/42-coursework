/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:45 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/10 11:51:13 by sbienias         ###   ########.fr       */
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
	if (type == 1)
		printf("%05ld %d is sleeping\n", time, phil->nbr);
	else if (type == 2)
	{
		printf("%05ld %d died\n", time, phil->nbr);
		*phil->death = 1;
	}
	else if (type == 3)
		printf("%05ld %d is thinking\n", time, phil->nbr);
	else if (type == 4)
	{
		printf("%05ld %d has taken a fork\n", time, phil->nbr);
		printf("%05ld %d has taken a fork\n", time, phil->nbr);
		printf("%05ld %d is eating\n", time, phil->nbr);
	}
	pthread_mutex_unlock(phil->printflag);
}

void	cleanup_memory(t_philo *phils, int counter)
{
	pthread_mutex_destroy(phils[0].dead);
	pthread_mutex_destroy(phils[0].access);
	pthread_mutex_destroy(phils[0].printflag);
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
	int	status;

	status = 0;
	number = ft_atoi(argv[1]);
	while (!status)
		status = check_for_death(phils, number);
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
	return (0);
}
