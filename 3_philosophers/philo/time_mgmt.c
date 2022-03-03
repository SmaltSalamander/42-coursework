/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:41:09 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/03 18:58:12 by sbienias         ###   ########.fr       */
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

long	format_micsec(long time)
{
	struct timeval	timetoconvert;
	long			result;

	gettimeofday(&timetoconvert, NULL);
	result = timetoconvert.tv_sec * 1000000;
	result += timetoconvert.tv_usec;
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
		//check_death(phil, phil->timersleep);
		//ft_usleep(phil->timersleep, *phil->time);
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

// void	ft_usleep(long	time, long timenow)
// {
// 	long	pres;
// 	//struct timeval	timetoconvert;

// 	pres = 0;
// 	printf("%ld %ld %ld\n", time, timenow, pres);
// 	while (pres < time)
// 	{
// 		usleep(100);
// 		// gettimeofday(&timetoconvert, NULL);
// 		// pres = timetoconvert.tv_sec * 1000000;
// 		// pres += timetoconvert.tv_usec;
// 		// pres -= timenow * 1000;
// 		//write(1, "here", 4);
// 		pres = format_micsec(timenow * 1000);
// 	}
// 	printf("%ld %ld %ld\n", time, timenow, pres);
// }

void	ft_usleep(long	time)
{
	// int	count;
	long	pres;
	struct timeval	timetoconvert;
	long			bef_loop;

	// count = 0;
	// pres = timetoconvert.tv_sec * 1000000;
	// pres += timetoconvert.tv_usec;
	gettimeofday(&timetoconvert, NULL);
	bef_loop = timetoconvert.tv_sec * 1000000;
	bef_loop += timetoconvert.tv_usec;
	// count = 2;
	while (1)
	{
		// count *= 2;
		usleep(10);
		gettimeofday(&timetoconvert, NULL);
		pres = timetoconvert.tv_sec * 1000000;
		pres += timetoconvert.tv_usec;
		if (pres > bef_loop + time)
			break ;
		// if (pres > bef_loop + time)
		// 	break ;
		//write(1, "here", 4);
		// time /= 100;
	}
}
