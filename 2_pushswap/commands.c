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

void	ft_rotating_rb(t_list **wrkngstck)
{
	t_list	*ele;

	ele = *wrkngstck;
	ft_lstadd_back(wrkngstck, ft_lstnew(ele->content));
	*wrkngstck = (*wrkngstck)->next;
	free(ele);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rotating_ra(t_list **arr)
{
	t_list	*ele;

	ele = *arr;
	ft_lstadd_back(arr, ft_lstnew(ele->content));
	*arr = (*arr)->next;
	free(ele);
	ft_putstr_fd("ra\n", 1);
}

void	issue_commands(t_list **arr, t_list	**wrkngstck, int *arrlen)
{
	t_list	*check1;

	check1 = (*arr)->next;
	if (check1 != 0x0)
	{
		if ((*(int *)(*arr)->content) > *(int *) check1->content)
			ft_swapping(*arr, *wrkngstck);
		while ((*(int *)(*arr)->content) < *(int *) check1->content)
		{
			if ((*wrkngstck))
			{
				ft_pushing_pa(arr, wrkngstck);
				*arrlen = *arrlen + 1;
				return ;
			}
			else if (*arrlen > 2)
			{
				ft_pushing_pb(arr, wrkngstck);
				*arrlen = *arrlen - 1;
			}
		}
	}
	else
	{
		if (*(int *) (*wrkngstck)->content)
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
