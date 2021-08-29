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

void	ft_swapping(t_list *arr, t_list *wrkngstck)
{
	int	temp;
	int	initswapb;

	initswapb = 0;
	if (wrkngstck)
	{
		if (wrkngstck->content && ft_lstsize(wrkngstck) > 1)
		{
			if (*(int *)wrkngstck->content < *(int *)(wrkngstck->next)->content)
			{
				temp = *(int *) wrkngstck->content;
				*(int *)wrkngstck->content = *(int *)(wrkngstck->next)->content;
				*(int *)(wrkngstck->next)->content = temp;
				initswapb = 1;
			}
		}
	}
	temp = *(int *) arr->content;
	*(int *)arr->content = *(int *)(arr->next)->content;
	*(int *)(arr->next)->content = temp;
	if (initswapb)
		ft_putstr_fd("ss\n", 1);
	else
		ft_putstr_fd("sa\n", 1);
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

void	sort_smallstack(t_list **arr, t_list	**arr1, int *arrlen)
{
	int		index;

	index = lookforval(*arr, 0);
	if (index == 0)
		ft_pushing_pb(arr, arr1, arrlen);
	else if (index <= (*arrlen / 2))
	{
		while (index != 0)
		{
			ft_rotating_ra(arr);
			index--;
		}
		ft_pushing_pb(arr, arr1, arrlen);
	}
	else
	{
		while (index != *arrlen)
		{
			ft_rev_rotating_ra(arr);
			index++;
		}
		ft_pushing_pb(arr, arr1, arrlen);
	}
}

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

int	*calc_median(t_list *arr, int amount)
{
	int	*res;
	int	*array;
	int	counter;
	int	size;

	counter = 0;
	size = ft_lstsize(arr);
	array = malloc(sizeof(int) * (size + 1));
	while (arr)
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
		res[counter] = array[size / (amount - counter + 1) + size % 2];
	res[counter++] = array[size - 1] + 1;
	res[counter] = 0;
	free(array);
	return (res);
}

void	push_to_work(t_list **arr, t_list **arr1, int *ls, int *arrlen)
{
	t_list	*copy;
	int		counter;
	int		frstcandidate;
	int		lastcandidate;

	counter = 0;
	frstcandidate = -1;
	lastcandidate = -1;
	copy = *arr;
	while (copy)
	{
		if (*(int *)copy->content >= *ls && frstcandidate == -1
			&& (*(ls + 1) == 0 || *(int *)copy->content < *(ls + 1)))
			frstcandidate = counter;
		if (*(int *)copy->content >= *ls
			&& (*(ls + 1) == 0 || *(int *)copy->content < *(ls + 1)))
			lastcandidate = counter;
		counter++;
		copy = copy->next;
	}
	if (lastcandidate != -1 && ft_lstsize(*arr) - lastcandidate < frstcandidate)
	{
		counter = lastcandidate - 1;
		while (lastcandidate++ < ft_lstsize(*arr))
			ft_rev_rotating_ra(arr);
		ft_pushing_pb(arr, arr1, arrlen);
		while (counter++ < ft_lstsize(*arr))
			ft_rotating_ra(arr);
	}
	else if (frstcandidate >= 0)
	{
		counter = frstcandidate - 1;
		while (frstcandidate-- > 0)
			ft_rotating_ra(arr);
		ft_pushing_pb(arr, arr1, arrlen);
		while (counter-- >= 0)
			ft_rev_rotating_ra(arr);
	}	
	if (frstcandidate == lastcandidate && frstcandidate == -1)
		return ;
	push_to_work(arr, arr1, ls, arrlen);
}

void	sort_stack(t_list **arr, t_list	**arr1, int *arrlen)
{
	int		index;
	int		small;

	index = lookforval(*arr1, 1);
	small = lookforval(*arr1, 0);
	if (index == 0 || small == 0)
	{
		ft_pushing_pa(arr, arr1, arrlen);
		if (small == 0)
			ft_rotating_ra(arr);
	}
	else if (index <= (*arrlen / 2) || small <= (*arrlen / 2))
	{
		while (index != 0 && small != 0)
		{
			ft_rotating_rb(arr1);
			index--;
			small--;
		}
		ft_pushing_pa(arr, arr1, arrlen);
		if (small == 0 && index != 0)
			ft_rotating_ra(arr);
	}
	else if (index > (*arrlen / 2) || small > (*arrlen / 2))
	{
		while (index != ft_lstsize(*arr1) && small != ft_lstsize(*arr1))
		{
			ft_rev_rotating_rb(arr1);
			index++;
			small++;
		}
		ft_pushing_pa(arr, arr1, arrlen);
		if (small == (ft_lstsize(*arr1) + 1) && index != ft_lstsize(*arr1))
			ft_rotating_ra(arr);
	}
	if (*arr1)
		sort_stack(arr, arr1, arrlen);
}

void	move_to_bottom(t_list **arr, int *ls)
{
	t_list	*check;
	t_list	*next;

	check = *arr;
	while (check)
	{
		next = check->next;
		if (*(int *)check->content >= *ls && *(int *)check->content < ls[1])
		{
			if (*(int *)next->content >= *ls && *(int *)next->content < ls[1]
				&& *(int *)check->content > *(int *)next->content)
				ft_swapping(*arr, 0);
			else
				ft_rotating_ra(arr);
		}
		else
			break ;
		check = next;
	}
}

void	issue_comms(t_list **arr, t_list	**wrkngstck, int *arrlen, int mode)
{
	int	*cutoff;
	int	counter;

	counter = 0;
	cutoff = 0;
	if (mode == 0)
		sort_smallstack(arr, wrkngstck, arrlen);
	//FIXTHIS
	else if (mode == 1)
	{
		cutoff = calc_median(*arr, 2);
		// push_to_work(arr, wrkngstck, cutoff, arrlen);
		// sort_stack(arr, wrkngstck, arrlen);
		while (counter < 2)
		{
			push_to_work(arr, wrkngstck, cutoff, arrlen);
			cutoff = cutoff + 1;
			counter++;
		}
		sort_stack(arr, wrkngstck, arrlen);
	}
	else
	{
		cutoff = calc_median(*arr, 2);
		// push_to_work(arr, wrkngstck, cutoff, arrlen);
		// sort_stack(arr, wrkngstck, arrlen);
		while (counter < 2)
		{
			push_to_work(arr, wrkngstck, cutoff, arrlen);
			sort_stack(arr, wrkngstck, arrlen);
			move_to_bottom(arr, cutoff);
			cutoff = cutoff + 1;
			counter++;
		}
		//sort_stack(arr, wrkngstck, arrlen);
	}
}

void	put_back(t_list **arr, t_list **wrkngstck, int *arrlen)
{
	t_list	*check1;

	check1 = (*arr)->next;
	if (check1 != 0x0)
		if ((*(int *)(*arr)->content) > *(int *) check1->content)
			ft_swapping(*arr, *wrkngstck);
	ft_pushing_pa(arr, wrkngstck, arrlen);
}

char	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int		lencpy;
	int		mode;

	if (arrlen <= 4)
		mode = 0;
	else if (arrlen <= 100)
		mode = 1;
	else
		mode = 1;
	lencpy = arrlen;
	workingstack = 0;
	while (ft_check_order(*arr, lencpy) || lencpy != arrlen)
	{
		issue_comms(arr, &workingstack, &lencpy, mode);
		if (lencpy <= 2)
			while (lencpy != arrlen)
				put_back(arr, &workingstack, &lencpy);
	}
	if (workingstack)
		ft_lstclear(&workingstack, free);
	return (0);
}
