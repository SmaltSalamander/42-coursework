/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:29:48 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/21 18:16:25 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(resultcopy);
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
	{
		free(number);
		return (1);
	}
	element = ft_lstnew((int *) number);
	ft_lstadd_back(array, element);
	return (0);
}

// Return 0 if the numbers are in ascending order, if not, return 1

int	ft_check_order(t_list *arr, int arrlen)
{
	int		counter;
	t_list	*check1;

	counter = 0;
	while (arr->next)
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

	while (array != NULL)
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
