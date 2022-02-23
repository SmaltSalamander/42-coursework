/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:00:41 by sbienias          #+#    #+#             */
/*   Updated: 2022/02/23 15:39:55 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h> //gettimeofday
# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include <unistd.h> // usleep

typedef struct s_philo {
	int				nbr;
	pthread_t		id;
	pthread_mutex_t	forkmut;
	pthread_mutex_t	*access;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*forknext;
	int				fork;
	int				*forkl;
	int				*death;
	int				neededmeals;
	pthread_mutex_t	*printflag;
	long			*time;
	long			lastmeal;
	long			timerdeath;
	long			timerfood;
	long			timersleep;
}		t_philo;

int	ft_atoi(const char *nptr);

#endif
