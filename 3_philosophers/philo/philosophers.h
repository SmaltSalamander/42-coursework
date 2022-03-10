/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:00:41 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/10 11:59:49 by sbienias         ###   ########.fr       */
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
	int				totalcount;
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

int		ft_atoi(const char *nptr);
void	try_eating(t_philo	*phil, int *state);
void	switch_forks(t_philo	*phil, int type);
void	*active_phils(void *arg);
void	print_request(t_philo *phil, int type);
int		handle_one_philo(char **argv);

// Time
long	format_time(long time);
void	sleep_time(t_philo	*phil, int *state);
void	set_timers(t_philo *phil, char **argv);
void	ft_usleep(long time);

int		init_phils(t_philo *phils, int argc, char **argv);

//Death
int		death_approaching(t_philo *phil);
int		has_starved(t_philo	*phil);
int		check_for_death(t_philo *phils, int num);

#endif
