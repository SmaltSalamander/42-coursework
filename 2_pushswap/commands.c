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

void	sort_wrk(t_list **arr, t_list	**wrkngstck)
{
	int		small;
	int		arrlen;

	arrlen = ft_lstsize(*wrkngstck);
	small = lookforval(*wrkngstck, 0);
	if (small >= arrlen / 2)
	{
		while (small != arrlen - 1)
		{
			ft_rev_rotating_rb(wrkngstck);
			small++;
		}
	}
	else
	{
		while (small >= 0)
		{
			ft_rotating_rb(wrkngstck);
			small--;
		}
	}
	if (*(int *)(*wrkngstck)->content < *(int *)(*wrkngstck)->next->content)
		ft_swapping(*arr, *wrkngstck);
}

void	push_to_work_half(t_list **arr, t_list **arr1, int *ls, int *arrlen)
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
		// while (counter++ < lastcandidate)
 		// 	ft_rotating_ra(arr);
	}
	else if (frstcandidate >= 0)
	{
		counter = frstcandidate - 1;
		while (frstcandidate-- > 0)
			ft_rotating_ra(arr);
		ft_pushing_pb(arr, arr1, arrlen);
	}
	if (*arr1 && ft_lstsize(*arr1) > 2)
		sort_wrk(arr, arr1);
	if (frstcandidate == lastcandidate && frstcandidate == -1)
		return ;
	push_to_work_half(arr, arr1, ls, arrlen);
}



// void	push_to_work(t_list **arr, t_list **arr1, int *ls, int *arrlen)
// {
// 	t_list	*copy;
// 	int		counter;
// 	int		frstcandidate;
// 	int		lastcandidate;

// 	counter = 0;
// 	frstcandidate = -1;
// 	lastcandidate = -1;
// 	copy = *arr;
// 	while (copy)
// 	{
// 		if (*(int *)copy->content >= *ls && frstcandidate == -1
// 			&& (*(ls + 1) == 0 || *(int *)copy->content < *(ls + 1)))
// 			frstcandidate = counter;
// 		if (*(int *)copy->content >= *ls
// 			&& (*(ls + 1) == 0 || *(int *)copy->content < *(ls + 1)))
// 			lastcandidate = counter;
// 		counter++;
// 		copy = copy->next;
// 	}
// 	if (lastcandidate != -1 && ft_lstsize(*arr) - lastcandidate < frstcandidate)
// 	{
// 		counter = lastcandidate - 1;
// 		while (lastcandidate++ < ft_lstsize(*arr))
// 			ft_rev_rotating_ra(arr);
// 		ft_pushing_pb(arr, arr1, arrlen);
// 		while (counter++ < ft_lstsize(*arr))
// 			ft_rotating_ra(arr);
// 	}
// 	else if (frstcandidate >= 0)
// 	{
// 		counter = frstcandidate - 1;
// 		while (frstcandidate-- > 0)
// 			ft_rotating_ra(arr);
// 		ft_pushing_pb(arr, arr1, arrlen);
// 		while (counter-- >= 0)
// 			ft_rev_rotating_ra(arr);
// 	}	
// 	if (frstcandidate == lastcandidate && frstcandidate == -1)
// 		return ;
// 	push_to_work(arr, arr1, ls, arrlen);
// }
void	push_to_work(t_list **arr, t_list **arr1, int *ls, int *arrlen)
{
	t_list	*copy;
	int		counter;
	int		lencpy;

	lencpy = *arrlen;
	counter = 0;
	copy = *arr;
	while (copy)
	{
		if (*(int *)copy->content >= *ls
			&& (*(ls + 1) == 0 || *(int *)copy->content < *(ls + 1)))
		{
			ft_pushing_pb(arr, arr1, arrlen);
			copy = *arr;
		}
		else
		{
			copy = copy->next;
			if (counter == lencpy)
				break ;
			ft_rotating_ra(arr);
		}
		if (*arr1 && ft_lstsize(*arr1) > 2)
			sort_wrk(arr, arr1);
		counter++;
	}
}
// void	sort_stack(t_list **arr, t_list	**arr1, int *arrlen)
// {
// 	int		index;
// 	int		small;

// 	index = lookforval(*arr1, 1);
// 	small = lookforval(*arr1, 0);
// 	if (index == 0 || small == 0)
// 	{
// 		ft_pushing_pa(arr, arr1, arrlen);
// 		if (small == 0)
// 			ft_rotating_ra(arr);
// 	}
// 	else if (index <= (*arrlen / 2) || small + 1 <= (*arrlen / 2))
// 	{
// 		while (index != 0 && small != 0)
// 		{
// 			ft_rotating_rb(arr1);
// 			index--;
// 			small--;
// 		}
// 		ft_pushing_pa(arr, arr1, arrlen);
// 		if (small == 0 && index != 0)
// 			ft_rotating_ra(arr);
// 	}
// 	else if (index > (*arrlen / 2) || small > (*arrlen / 2) + 1)
// 	{
// 		while (index != ft_lstsize(*arr1) && small != ft_lstsize(*arr1))
// 		{
// 			ft_rev_rotating_rb(arr1);
// 			index++;
// 			small++;
// 		}
// 		ft_pushing_pa(arr, arr1, arrlen);
// 		if (small == (ft_lstsize(*arr1)) + 1 && index != small
// 			&& *arr)
// 			ft_rotating_ra(arr);
// 	}
// 	if (*arr1)
// 		sort_stack(arr, arr1, arrlen);
// }
void	sort_stack(t_list **arr, t_list	**arr1, int *arrlen)
{
	int		index;

	index = lookforval(*arr1, 1);
	if (index == 0)
	{
		ft_pushing_pa(arr, arr1, arrlen);
	}
	else if (index <= (*arrlen / 2))
	{
		while (index != 0)
		{
			ft_rotating_rb(arr1);
			index--;
		}
		ft_pushing_pa(arr, arr1, arrlen);
	}
	else if (index > (*arrlen / 2))
	{
		while (index != ft_lstsize(*arr1))
		{
			ft_rev_rotating_rb(arr1);
			index++;
		}
		ft_pushing_pa(arr, arr1, arrlen);
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

void	make_place(t_list **arr, t_list **arr1, int *arrlen)
{
	t_list	*copy;
	int		counter;

	counter = 0;
	copy = *arr;
	if (*(int *)(*arr1)->content > *(int *)copy->content && copy->next &&
		*(int *)(*arr1)->content < *(int *)copy->next->content)
	{
		ft_pushing_pa(arr, arr1, arrlen);
		ft_swapping(*arr, *arr1);
	}
	else
	{
		while (copy && *(int *)(*arr1)->content > *(int *)copy->content
			&& ft_lstsize(*arr) > 2)
		{
			copy = copy->next;
			ft_rotating_ra(arr);
			counter++;
		}
		ft_pushing_pa(arr, arr1, arrlen);
		while (counter--)
			ft_rev_rotating_ra(arr);
	}
}

void	ft_sortwrkng(t_list **arr, t_list **arr1, int *arrlen, int stcksize)
{
	int		counter;
	int		*median;

	counter = 0;
	if (stcksize == 1)
	{
		ft_pushing_pa(arr, arr1, arrlen);
		stcksize--;
	}
	else if (stcksize == 2)
	{
		if (*(int *)(*arr1)->content < *(int *)(*arr1)->next->content)
			ft_swapping(*arr, *arr1);
		ft_pushing_pa(arr, arr1, arrlen);
		stcksize--;
	}
	else
	{
		median = calc_median(*arr1, 2, stcksize);
		while (stcksize)
		{
			if (*(int *)(*arr1)->content < *(int *)(*arr1)->next->content
				|| ((*arr)->next && *(int *)(*arr)->content > *(int *)(*arr)->next->content))
				ft_swapping(*arr, *arr1);
			if (*(int *)(*arr1)->content >= median[1])
				make_place(arr, arr1, arrlen);
				// ft_pushing_pa(arr, arr1, arrlen);
			else
			{
				if (stcksize == 2)
					break ;
				ft_rotating_rb(arr1);
				counter++;
			}
			stcksize--;
		}
		if (counter)
		{
			stcksize += counter;
			while (counter--)
				ft_rev_rotating_rb(arr1);
		}
	}
	if (stcksize)
		ft_sortwrkng(arr, arr1, arrlen, stcksize);
}

void	test_sort(t_list **arr, t_list	**wrkngstck, int *arrlen)
{
	t_list	*last;
	t_list	*copy;
	int		*median;
	int		counter;

	counter = 0;
	median = calc_median(*arr, 2, -1);
	copy = *arr;
	last = ft_lstlast(*arr);
	while (1)
	{
		if (*(int *)copy->content <= median[1])
			ft_pushing_pb(arr, wrkngstck, arrlen);
		else if (*(int *)ft_lstlast(*arr)->content < median[1])
		{
			ft_rev_rotating_ra(arr);
			ft_pushing_pb(arr, wrkngstck, arrlen);
			last = ft_lstlast(*arr);
		}
		else
		{
			if (ft_lstsize(*arr) == 1)
				break ;
			// if (*wrkngstck && ft_lstsize(*wrkngstck) > 2)
			// sort_wrk(arr, wrkngstck);
			ft_rotating_ra(arr);
			counter--;
		}
		counter++;
		if (copy == last)
			break ;
		copy = *arr;
	}
	if (ft_lstsize(*arr) > 1)
	 	test_sort(arr, wrkngstck, arrlen);
	ft_sortwrkng(arr, wrkngstck, arrlen, counter);
}
void	issue_comms(t_list **arr, t_list	**wrkngstck, int *arrlen, int mode)
{
	int	*cutoff;
	int	counter;

	counter = 0;
	cutoff = 0;
	if (mode == 0)
		sort_smallstack(arr, wrkngstck, arrlen);
	else if (mode == 1)
	{
		// cutoff = calc_median(*arr, 2);
		// while (counter < 2)
		// {
		// 	push_to_work_half(arr, wrkngstck, cutoff, arrlen);
		// 	sort_stack(arr, wrkngstck, arrlen);
		// 	cutoff = cutoff + 1;
		// 	counter++;
		// }
		// move_to_bottom(arr, cutoff - 1);

		test_sort(arr, wrkngstck, arrlen);
		// test_sort_wrkng(arr, wrkngstck, arrlen);
		// sort_stack(arr, wrkngstck, arrlen);
	}
	else
	{
		cutoff = calc_median(*arr, 22, -1);
		while (counter < 22)
		{
			push_to_work(arr, wrkngstck, cutoff, arrlen);
			cutoff = cutoff + 1;
			counter++;
		}
		sort_stack(arr, wrkngstck, arrlen);
		move_to_bottom(arr, cutoff - 1);
	}
	// if (cutoff)
	// 	free(cutoff);
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

void	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int		lencpy;
	int		mode;

	if (arrlen <= 5)
		mode = 0;
	else if (arrlen <= 100)
		mode = 1;
	else
		mode = 2;
	lencpy = arrlen;
	workingstack = 0;
	while (ft_check_order(*arr, lencpy) || lencpy != arrlen)
	{
		issue_comms(arr, &workingstack, &lencpy, mode);
	}
	if (workingstack)
		ft_lstclear(&workingstack, free);
	return ;
}
