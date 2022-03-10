/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:39:08 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/10 13:44:07 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_for_death(t_philo *phils, int num)
{
	int	counter;
	int	status;

	counter = 0;
	status = 0;
	while (!status && counter < num)
	{
		status = has_starved(&phils[counter]);
		counter++;
	}
	return (status);
}

int	has_starved(t_philo	*phil)
{
	long	t;
	int		status;

	t = format_time(*phil->time);
	pthread_mutex_lock(&(*phil->dead));
	status = 0;
	if (*phil->death)
		status = 1;
	else if (!*phil->death && ((t - phil->lastmeal) >= phil->tdeath / 1000 + 2))
	{
		print_request(phil, 2);
		status = 1;
	}
	pthread_mutex_unlock(&(*phil->dead));
	return (status);
}

int	death_approaching(t_philo *phil)
{
	long	timenow;

	timenow = format_time(*phil->time);
	if ((timenow - phil->lastmeal) >= (phil->tdeath / 1000) / 3)
		return (1);
	else
		return (0);
}
