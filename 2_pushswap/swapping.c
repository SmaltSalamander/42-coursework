/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:53:23 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/13 15:32:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_swapping_sb(t_list *wrkngstck)
{
	int	temp;

	if (wrkngstck->content && ft_lstsize(wrkngstck) > 1)
	{
		if (*(int *)wrkngstck->content < *(int *)(wrkngstck->next)->content)
		{
			temp = *(int *) wrkngstck->content;
			*(int *)wrkngstck->content = *(int *)(wrkngstck->next)->content;
			*(int *)(wrkngstck->next)->content = temp;
			return (1);
		}
	}
	return (0);
}

int	ft_swapping_sa(t_list *arr)
{
	int	temp;

	if (*(int *)arr->content > *(int *)(arr->next)->content)
	{
		temp = *(int *) arr->content;
		*(int *)arr->content = *(int *)(arr->next)->content;
		*(int *)(arr->next)->content = temp;
		return (1);
	}
	return (0);
}

void	ft_swapping(t_list *arr, t_list *wrkngstck, int print)
{
	int	initswapb;
	int	initswapa;

	initswapb = 0;
	initswapa = 0;
	if (wrkngstck && wrkngstck->next)
	{
		initswapb = ft_swapping_sb(wrkngstck);
	}
	if (arr && arr->next)
	{
		initswapa = ft_swapping_sa(arr);
	}
	if (!print)
		return ;
	if (initswapb && initswapa)
		ft_putstr_fd("ss\n", 1);
	else if (!initswapb && initswapa)
		ft_putstr_fd("sa\n", 1);
	else if (initswapb && !initswapa)
		ft_putstr_fd("sb\n", 1);
}
