/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:50:59 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 09:50:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	counter;
	int	is_negative;
	int	result;

	is_negative = 1;
	result = 0;
	counter = 0;
	while (ft_isspace(*(nptr + counter)) == 1)
		counter++;
	if (*(nptr + counter) == '+' || *(nptr + counter) == '-')
	{
		if (*(nptr + counter) == '-')
		{
			is_negative *= -1;
		}
		counter++;
	}
	while (*(nptr + counter) >= '0' && *(nptr + counter) <= '9')
	{
		result *= 10;
		result += *(nptr + counter) - '0';
		counter++;
	}
	result *= is_negative;
	return (result);
}

int	handle_one_philo(char **argv)
{
	pthread_t		id;

	if (pthread_create(&id, NULL, handle_one, \
		argv))
	{
		printf("Thread creation error detected\n");
		return (2);
	}
	pthread_join(id, NULL);
	return (1);
}
