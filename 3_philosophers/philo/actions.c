/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:43 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/03 19:46:39 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*active_phils(void *arg)
{
	t_philo	*phil;
	int		state;

	state = 0;
	phil = ((t_philo *) arg);
	if (phil->nbr % 2 == 1)
		usleep(50);
	while (phil->neededmeals && !has_starved(phil))
	{
		if (state == 2)
		{
			print_request(phil, 3);
			state = 0;
			usleep(50);
		}
		try_eating(phil, &state);
		sleep_time(phil, &state);
	}
	pthread_exit(NULL);
	return (NULL);
}

int		death_approaching(t_philo *phil)
{
	long	timenow;

	timenow = format_time(*phil->time);
	if ((timenow - phil->lastmeal) >= (phil->timerdeath / 1000) / 3)
		return (1);
	else
		return (0);
}

void	grab_fork(t_philo	*phil, int type)
{
	pthread_mutex_lock(&(*phil->access));
	if (type == 0)
	{
		pthread_mutex_lock(&(*phil->forknext));
		*phil->forkl = 0;
	}
	else
	{
		pthread_mutex_lock(&phil->forkmut);
		phil->fork = 0;
	}
	pthread_mutex_unlock(&(*phil->access));
}

void	try_eating(t_philo	*phil, int *state)
{
	if (*state == 0)
	{
		pthread_mutex_lock(&(*phil->access));
		if (!phil->fork || !*phil->forkl)
		{
			if (!death_approaching(phil))
			{
				pthread_mutex_unlock(&(*phil->access));
				return ;
			}
		}
		phil->fork = 0;
		*phil->forkl = 0;
		pthread_mutex_unlock(&(*phil->access));
		pthread_mutex_lock(&(*phil->forknext));
		pthread_mutex_lock(&phil->forkmut);
		print_request(phil, 4);
		pthread_mutex_lock(&(*phil->dead));
		phil->lastmeal = format_time(*phil->time);
		print_request(phil, 0);
		pthread_mutex_unlock(&(*phil->dead));
		ft_usleep(phil->timerfood);
		pthread_mutex_lock(&(*phil->access));
		phil->fork = 1;
		*phil->forkl = 1;
		pthread_mutex_unlock(&(*phil->access));
		pthread_mutex_unlock(&(*phil->forknext));
		pthread_mutex_unlock(&phil->forkmut);
		phil->neededmeals -= 1;
		*state = 1;
	}
}
