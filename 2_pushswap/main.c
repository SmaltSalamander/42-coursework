/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:36:45 by sbienias          #+#    #+#             */
/*   Updated: 2021/07/22 12:36:45 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include "pushswap.h"

int	error_check_atoi(char *string, int *arrelement)
{
	char	*resultcopy;
	int		numberlen;

	*arrelement = ft_atoi(string);
	resultcopy = ft_itoa(*arrelement);
	numberlen = ft_strlen(string);
	if (ft_strncmp(string, resultcopy, numberlen) == 0)
		return (numberlen);
	return (-1);
}

int	ft_add_to_array(char *string, int *array)
{
	int		number;
	int		error;

	error = error_check_atoi(string, &number);
	if (error == -1)
		return (1);
	*(int *)(array) = number;
	return (0);
}

// Return 0 if the numbers are in ascending order, if not, return 1

int	ft_check_order(int *arr, int arrlen)
{
	int	counter;

	counter = 0;
	while (counter < arrlen - 1)
	{
		if (*(arr + counter) > *(arr + counter + 1))
			break ;
		counter++;
	}
	if (counter == arrlen - 1)
		return (0);
	return (1);
}

char	ft_sort(int *arr, int arrlen)
{
	int	*workingstack;
	int	*arrstart;
	int	*wrkstckstart;
	int lencpy;

	lencpy = arrlen;
	arrstart = arr;
	workingstack = ft_calloc(arrlen, sizeof(int));
	if (!workingstack)
		return (1);
	wrkstckstart = workingstack;
	while (ft_check_order(arrstart, arrlen) || *wrkstckstart)
	{
		issue_commands(&arr, &workingstack, wrkstckstart, &lencpy);
		for (int x = 0; x < lencpy; x++)
		{
			ft_printf("Len %d Print arr value %d, index %d \n", lencpy, *(arr + x), x);
		}
	}
	return (0);
	
}

int	main(int argc, char **argv)
{
	int	*array;
	int	error;
	int	counter;

	counter = 0;
	if (argc > 1)
	{
		array = malloc((argc - 1) * sizeof(int));
		if (!array)
			error = 1;
		while (counter < (argc - 1) && error != 1)
		{
			error = ft_add_to_array(*(argv + 1 + counter), (array + counter));
			counter++;
		}
		if (error == 0)
		{
			ft_sort(array, (argc - 1));
			return (0);
		}
	}
	if (array)
		free(array);
	write(1, "Error\n", 6);
	return (1);
}
