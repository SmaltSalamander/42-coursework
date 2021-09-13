/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:09:21 by sbienias          #+#    #+#             */
/*   Updated: 2021/07/23 15:09:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_to_work(t_list **arr, t_list **arr1, int *ls, int *arrlen)
{
	int		*candidates;

	candidates = canidadates_in_range(arr, ls);
	if (candidates[1] != -1 && ft_lstsize(*arr) - candidates[1] < candidates[0])
	{
		while (candidates[1]++ < ft_lstsize(*arr))
			ft_rev_rotating_ra(arr, 1);
		ft_pushing_pb(arr, arr1, arrlen, 1);
	}
	else if (candidates[0] >= 0)
	{
		while (candidates[0]-- > 0)
			ft_rotating_ra(arr, 1);
		ft_pushing_pb(arr, arr1, arrlen, 1);
	}	
	if (candidates[0] == candidates[1] && candidates[0] == -1)
		return ;
	push_to_work(arr, arr1, ls, arrlen);
}

void	sort_stack(t_list **arr, t_list	**arr1, int *arrlen)
{
	int		index;
	int		arr1len;

	arr1len = ft_lstsize(*arr1);
	index = lookforval(*arr1, 1);
	if (index <= (arr1len / 2))
	{
		while (index != 0)
		{
			ft_rotating_rb(arr1, 1);
			index--;
		}
		ft_pushing_pa(arr, arr1, arrlen, 1);
	}
	else if (index >= (arr1len / 2))
	{
		while (index != arr1len)
		{
			ft_rev_rotating_rb(arr1, 1);
			index++;
		}
		ft_pushing_pa(arr, arr1, arrlen, 1);
	}
	if (*arr1)
		sort_stack(arr, arr1, arrlen);
}

void	move_to_bottom(t_list **arr, int ls)
{
	t_list	*check;
	int		counter;
	int		index;
	int		smallest;

	smallest = valatindex(*arr, lookforval(*arr, 0));
	counter = 0;
	index = 0;
	check = *arr;
	while (check)
	{
		if (*(int *)check->content <= ls && *(int *)check->content > smallest)
		{
			smallest = *(int *)check->content;
			index = counter;
		}
		check = check->next;
		counter++;
	}
	if (index <= ft_lstsize(*arr) / 2)
		while (index--)
			ft_rotating_ra(arr, 1);
	else
		while (index++ < ft_lstsize(*arr))
			ft_rev_rotating_ra(arr, 1);
}

void	issue_comms(t_list **arr, t_list	**wrkngstck, int *arrlen, int parts)
{
	int	*cutoff;
	int	counter;
	int	element;

	counter = 0;
	cutoff = 0;
	if (parts == 0)
		sort_smallstack(arr, wrkngstck, arrlen);
	else
	{
		cutoff = calc_median(*arr, parts, -1);
		while (counter < parts)
		{
			push_to_work(arr, wrkngstck, cutoff, arrlen);
			if (counter)
				move_to_bottom(arr, element);
			sort_stack(arr, wrkngstck, arrlen);
			cutoff = cutoff + 1;
			element = *(int *)(*arr)->content;
			counter++;
		}
	}
}

void	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int		lencpy;
	int		parts;

	if (arrlen <= 5)
		parts = 0;
	else if (arrlen <= 100)
		parts = 4;
	else
		parts = 9;
	lencpy = arrlen;
	workingstack = 0;
	while (ft_check_order(*arr, lencpy) || lencpy != arrlen)
	{
		issue_comms(arr, &workingstack, &lencpy, parts);
	}
	if (workingstack)
		ft_lstclear(&workingstack, free);
	return ;
}
