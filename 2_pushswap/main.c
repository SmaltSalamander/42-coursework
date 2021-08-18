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
	{
		free(resultcopy);
		return (numberlen);
	}
	return (-1);
}

int	ft_add_to_array(char *string, t_list **array)
{
	int		*number;
	int		error;
	t_list	*element;

	number = malloc(sizeof(int));
	error = error_check_atoi(string, number);
	if (error == -1)
		return (1);
	element = ft_lstnew((int *) number);
	ft_lstadd_back(array, element);
	// *(int *)(array) = number;
	return (0);
}

// Return 0 if the numbers are in ascending order, if not, return 1

int	ft_check_order(t_list *arr, int arrlen)
{
	int	counter;
	t_list	*check1;

	counter = 0;
	while (counter < arrlen - 1)
	{
		check1 = arr -> next;
		if (*(int *) arr->content > *(int *) check1->content)
			break ;
		counter++;
		arr = arr -> next;
	}
	if (counter == arrlen - 1)
		return (0);
	return (1);
}

int	dup_check(t_list *array)
{
	t_list	*check1;

	while (array->next)
	{
		check1 = array->next;
		while (check1)
		{
			if (*(int *) check1->content == *(int *) array->content)
				return (1);
			check1 = check1->next;
		}
		array = array->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	error;
	int	counter;
	t_list	*arr;

	counter = -1;
	error = 0;
	arr = 0;
	if (argc > 1)
	{
		while (++counter < (argc - 1) && error != 1)
			error = ft_add_to_array(*(argv + 1 + counter), &arr);
		// t_list *copy = arr;
		// while (copy != NULL)
		// {
		// 	ft_printf("%d\n", *(int *)copy->content);
		// 	copy = copy->next;
		// }
		error = dup_check(arr);
		if (error == 0)
		 	ft_sort(&arr, (argc - 1));
	}
	else
		error = 1;
	if (arr)
		ft_lstclear(&arr, free);
	if (!error)
		return (0);
	write(1, "Error\n", 6);
	return (1);
}
