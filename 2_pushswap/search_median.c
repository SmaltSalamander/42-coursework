/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:45:32 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/02 21:52:00 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_srtarr(int **array, int size)
{
	int	counter;
	int	j;
	int	check;

	counter = 0;
	while (counter < size)
	{
		j = counter + 1;
		while (j < size)
		{
			if ((*array)[counter] > (*array)[j])
			{
				check = (*array)[counter];
				(*array)[counter] = (*array)[j];
				(*array)[j] = check;
			}
			j++;
		}
		counter++;
	}
}

int	*calc_median(t_list *arr, int amount, int size)
{
	int	*res;
	int	*array;
	int	counter;

	counter = 0;
	if (size == -1)
		size = ft_lstsize(arr);
	array = malloc(sizeof(int) * (size + 1));
	while (arr && counter != size)
	{
		array[counter] = *(int *)arr->content;
		arr = arr->next;
		counter++;
	}
	ft_srtarr(&array, size);
	res = malloc(sizeof(int) * (amount + 2));
	counter = 0;
	res[counter] = array[counter];
	while (++counter < amount)
		res[counter] = array[(size / amount) * counter + (size % amount)];
	res[counter++] = array[size - 1] + 1;
	res[counter] = 0;
	free(array);
	return (res);
}

int	lookforval(t_list *arr, int mode)
{
	int	index;
	int	value;
	int	temp;

	temp = 0;
	value = *(int *)(arr)->content;
	index = 0;
	while (arr)
	{
		if (*(int *)(arr)->content < value && mode == 0)
		{
			value = *(int *)(arr)->content;
			index = temp;
		}
		else if (*(int *)(arr)->content > value && mode == 1)
		{
			value = *(int *)(arr)->content;
			index = temp;
		}
		temp++;
		arr = arr->next;
	}
	return (index);
}