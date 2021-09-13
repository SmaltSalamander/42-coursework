/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:23:15 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/13 15:34:44 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// rb : rotate b - shift up all elements of stack b by 1.
// The first element becomes the last one.

void	ft_rotating_rb(t_list **wrkngstck, int print)
{
	t_list	*ele;
	t_list	*last;

	ele = *wrkngstck;
	*wrkngstck = (*wrkngstck)->next;
	last = ft_lstlast(*wrkngstck);
	last->next = ele;
	ele->next = 0x0;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

// ra : rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ft_rotating_ra(t_list **arr, int print)
{
	t_list	*ele;
	t_list	*last;

	ele = *arr;
	*arr = (*arr)->next;
	last = ft_lstlast(*arr);
	last->next = ele;
	ele->next = 0x0;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

// rrb : reverse rotate b - shift down all elements of stack b by 1.
// The last element becomes the first one.

void	ft_rev_rotating_rb(t_list **wrkngstck, int print)
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
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

// rra : reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one.

void	ft_rev_rotating_ra(t_list **arr, int print)
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
	if (print)
		ft_putstr_fd("rra\n", 1);
}
