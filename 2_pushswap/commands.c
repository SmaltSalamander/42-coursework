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

#include "./libft/libft.h"
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

void	ft_pushing_pb(t_list **arr, t_list **wrkngstck)
{
	t_list	*ele;

	ele = *arr;
	ft_lstadd_front(wrkngstck, ft_lstnew(ele->content));
	*arr = (*arr)->next;
	free(ele);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pushing_pa(t_list **arr, t_list **wrkngstck)
{
	t_list	*ele;

	ele = *wrkngstck;
	ft_lstadd_front(arr, ft_lstnew(ele->content));
	*wrkngstck = (*wrkngstck)->next;
	free(ele);
	ft_putstr_fd("pa\n", 1);
}

// rb : rotate b - shift up all elements of stack b by 1.
// The first element becomes the last one.

void	ft_rotating_rb(t_list **wrkngstck)
{
	t_list	*ele;

	ele = *wrkngstck;
	ft_lstadd_back(wrkngstck, ft_lstnew(ele->content));
	*wrkngstck = (*wrkngstck)->next;
	ft_lstdelone(ele, free);
	ft_putstr_fd("rb\n", 1);
}

// ra : rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ft_rotating_ra(t_list **arr)
{
	t_list	*ele;

	ele = *arr;
	ft_lstadd_back(arr, ft_lstnew(ele->content));
	*arr = (*arr)->next;
	ft_lstdelone(ele, free);
	ft_putstr_fd("ra\n", 1);
}

// rrb : reverse rotate b - shift down all elements of stack b by 1.
// The last element becomes the first one.

void	ft_rev_rotating_rb(t_list **wrkngstck)
{
	t_list	*ele;
	t_list	*cpy;

	ele = ft_lstlast(*wrkngstck);
	ft_lstadd_front(wrkngstck, ft_lstnew(ele->content));
	cpy = *wrkngstck;
	while (cpy->next != ele)
		cpy = cpy->next;
	cpy->next = 0;
	free(ele);
	ft_putstr_fd("rrb\n", 1);
}

// rra : reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one.

void	ft_rev_rotating_ra(t_list **arr)
{
	t_list	*ele;
	t_list	*cpy;

	ele = ft_lstlast(*arr);
	ft_lstadd_front(arr, ft_lstnew(ele->content));
	cpy = *arr;
	while (cpy->next != ele)
		cpy = cpy->next;
	cpy->next = 0;
	free(ele);
	ft_putstr_fd("rra\n", 1);
}

void	issue_commands(t_list **arr, t_list	**wrkngstck, int *arrlen)
{
	t_list	*check1;
	int		last;
	t_list	*lastlst;

	lastlst = ft_lstlast(*arr);
	last = *(int *)lastlst->content;
	check1 = (*arr)->next;
	if (check1 != 0x0)
	{
		if ((*(int *)(*arr)->content) > *(int *) check1->content)
			ft_swapping(*arr, *wrkngstck);
		else if (last < *(int *)(*arr)->content)
			ft_rev_rotating_ra(arr);
		else if ((*(int *)(*arr)->content) < *(int *) check1->content)
		{
			if ((*wrkngstck))
			{
				ft_pushing_pa(arr, wrkngstck);
				*arrlen = *arrlen + 1;
				return ;
			}
			while (*arrlen > 2)
			{
				ft_pushing_pb(arr, wrkngstck);
				*arrlen = *arrlen - 1;
			}
		}
	}
	else
	{
		if (*(int *)(*wrkngstck)->content)
		{
			ft_pushing_pa(arr, wrkngstck);
			*arrlen = *arrlen + 1;
			return ;
		}
	}
}

char	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int		lencpy;

	lencpy = arrlen;
	workingstack = 0;
	while (ft_check_order(*arr, lencpy) || lencpy != arrlen)
	{
		issue_commands(arr, &workingstack, &lencpy);
	}
	if (workingstack)
		ft_lstclear(&workingstack, free);
	return (0);
}
