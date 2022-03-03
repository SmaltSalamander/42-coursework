/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:41:09 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/03 19:47:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	sleep_time(t_philo	*phil, int *state)
{
	if (has_starved(phil))
		return ;
	if (*state == 1)
	{
		print_request(phil, 1);
		ft_usleep(phil->timersleep - 2000);
		*state = 2;
	}
}

void	set_timers(t_philo *phil, char **argv)
{
	phil->timerdeath = ft_atoi(argv[2]) * 1000;
	phil->timerfood = ft_atoi(argv[3]) * 1000;
	phil->timersleep = ft_atoi(argv[4]) * 1000;
}

void	ft_usleep(long	time)
{
	long			pres;
	struct timeval	timetoconvert;
	long			bef_loop;

	gettimeofday(&timetoconvert, NULL);
	bef_loop = timetoconvert.tv_sec * 1000000;
	bef_loop += timetoconvert.tv_usec;
	while (1)
	{
		usleep(10);
		gettimeofday(&timetoconvert, NULL);
		pres = timetoconvert.tv_sec * 1000000 + timetoconvert.tv_usec;
		if (pres > bef_loop + time)
			break ;
	}
}
