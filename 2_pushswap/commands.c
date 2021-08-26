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

int	lookforsmallest(t_list *arr)
{
	int	index;
	int	value;
	int	temp;

	temp = 0;
	value = *(int *)(arr)->content;
	index = 0;
	while (arr)
	{
		if (*(int *)(arr)->content < value)
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

	index = lookforsmallest(*arr);
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

void	issue_comms(t_list **arr, t_list	**wrkngstck, int *arrlen, int mode)
{
	int	cutoff;
	int	counter;

	counter = 0;
	cutoff = 0;
	if (mode == 0)
	{
		sort_smallstack(arr, wrkngstck, arrlen);
	}
	else if (mode == 1)
	{
		while (counter < 2)
		{
			cutoff = calc_median(*arr, 2);
			push_to_work(arr, cutoff);
			sort_work(wrkngstck);
			while ((*wrkngstck)->next)
			{
				ft_pushing_pa(arr, wrkngstck, arrlen);
				*wrkngstck = (*wrkngstck)->next;
			}
			counter++;
		}
	}
	else
	{
		while (counter < 10)
		{
			cutoff = calc_median(*arr, 10);
			push_to_work(arr, cutoff);
			sort_work(wrkngstck);
			while ((*wrkngstck)->next)
			{
				ft_pushing_pa(arr, wrkngstck, arrlen);
				*wrkngstck = (*wrkngstck)->next;
			}
			counter++;
		}
	}
	}

// void	issue_commands(t_list **arr, t_list	**wrkngstck, int *arrlen)
// {
// 	int		index;

// 	index = lookforsmallest(*arr);
// 	if (index == 0)
// 		ft_pushing_pb(arr, wrkngstck, arrlen);
// 	else if (index <= (*arrlen / 2))
// 	{
// 		while (index != 0)
// 		{
// 			ft_rotating_ra(arr);
// 			index--;
// 		}
// 		ft_pushing_pb(arr, wrkngstck, arrlen);
// 	}
// 	else
// 	{
// 		while (index != *arrlen)
// 		{
// 			ft_rev_rotating_ra(arr);
// 			index++;
// 		}
// 		ft_pushing_pb(arr, wrkngstck, arrlen);
// 	}
// }

void	put_back(t_list **arr, t_list **wrkngstck, int *arrlen)
{
	t_list	*check1;

	check1 = (*arr)->next;
	if (check1 != 0x0)
		if ((*(int *)(*arr)->content) > *(int *) check1->content)
			ft_swapping(*arr, *wrkngstck);
	ft_pushing_pa(arr, wrkngstck, arrlen);
}

// void	issue_commands(t_list **arr, t_list	**wrkngstck, int *arrlen)
// {
// 	t_list	*check1;
// 	int		last;

// 	last = *(int *)(ft_lstlast(*arr))->content;
// 	check1 = (*arr)->next;
// 	if (check1 != 0x0)
// 	{
// 		if ((*(int *)(*arr)->content) > *(int *) check1->content)
// 			ft_swapping(*arr, *wrkngstck);
// 		else if (last < *(int *)(*arr)->content)
// 			ft_rev_rotating_ra(arr);
// 		else if ((*(int *)(*arr)->content) < *(int *) check1->content)
// 		{
// 			if ((*wrkngstck))
// 			{
// 				ft_pushing_pa(arr, wrkngstck, arrlen);
// 				return ;
// 			}
// 			while (*arrlen > 2)
// 			{
// 				ft_pushing_pb(arr, wrkngstck, arrlen);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (*(int *)(*wrkngstck)->content)
// 		{
// 			ft_pushing_pa(arr, wrkngstck, arrlen);
// 			return ;
// 		}
// 	}
// }

char	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int		lencpy;
	int		mode;

	if (arrlen <= 10)
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
		if (lencpy <= 2)
			while (lencpy != arrlen)
				put_back(arr, &workingstack, &lencpy);
	}
	if (workingstack)
		ft_lstclear(&workingstack, free);
	return (0);
}
