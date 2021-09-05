/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:23:15 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/05 20:51:54 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// rb : rotate b - shift up all elements of stack b by 1.
// The first element becomes the last one.

void	ft_rotating_rb(t_list **wrkngstck)
{
	t_list	*ele;
	t_list	*last;

	ele = *wrkngstck;
	*wrkngstck = (*wrkngstck)->next;
	last = ft_lstlast(*wrkngstck);
	last->next = ele;
	ele->next = 0x0;
	ft_putstr_fd("rb\n", 1);
}

// ra : rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ft_rotating_ra(t_list **arr)
{
	t_list	*ele;
	t_list	*last;

	ele = *arr;
	*arr = (*arr)->next;
	last = ft_lstlast(*arr);
	last->next = ele;
	ele->next = 0x0;
	ft_putstr_fd("ra\n", 1);
}

// void	ft_rotating(t_list **arr, t_list **wrkngstck)
// {
// 	int	initrotb;
// 	int	initrota;

// 	initrotb = 0;
// 	initrota = 0;
// 	if (wrkngstck && wrkngstck->next)
// 	{
// 		if (*(int *)(*wrkngstck)->content )
// 		initrotb = ft_swapping_sb(wrkngstck);
// 	}
// 	if (arr && arr->next)
// 	{
// 		initrota = ft_swapping_sa(arr);
// 	}
// 	if (initrotb && initrota)
// 		ft_putstr_fd("ss\n", 1);
// 	else if (!initrotb && initrota)
// 		ft_putstr_fd("sa\n", 1);
// 	else if (initrotb && !initrota)
// 		ft_putstr_fd("sb\n", 1);	
// }

// rrb : reverse rotate b - shift down all elements of stack b by 1.
// The last element becomes the first one.

void	ft_rev_rotating_rb(t_list **wrkngstck)
{
	t_list	*ele;
	t_list	*cpy;

	ele = ft_lstlast(*wrkngstck);
	ele->next = *wrkngstck;
	*wrkngstck = ele;
	cpy = *wrkngstck;
	while (cpy->next != ele)
		cpy = cpy->next;
	cpy->next = 0x0;
	ft_putstr_fd("rrb\n", 1);
}

// rra : reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one.

void	ft_rev_rotating_ra(t_list **arr)
{
	t_list	*ele;
	t_list	*cpy;

	ele = ft_lstlast(*arr);
	ele->next = *arr;
	*arr = ele;
	cpy = *arr;
	while (cpy->next != ele)
		cpy = cpy->next;
	cpy->next = 0x0;
	ft_putstr_fd("rra\n", 1);
}