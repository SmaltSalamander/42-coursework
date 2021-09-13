/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:43:41 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/13 15:37:37 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_list **arr, t_list **arr1, int *arrlen)
{
	int		big;

	big = lookforval(*arr, 1);
	if (big >= *arrlen / 2)
	{
		while (big != *arrlen - 1)
		{
			ft_rev_rotating_ra(arr, 1);
			big++;
		}
	}
	else
	{
		while (big >= 0)
		{
			ft_rotating_ra(arr, 1);
			big--;
		}
	}
	if (*(int *)(*arr)->content > *(int *)(*arr)->next->content)
		ft_swapping(*arr, *arr1, 1);
}

void	sort_smallstack(t_list **arr, t_list **arr1, int *arrlen)
{
	int	small;

	small = lookforval(*arr, 0);
	while (*arrlen > 3)
	{
		if (small > *arrlen / 2)
		{
			while (small++ != *arrlen)
				ft_rev_rotating_ra(arr, 1);
		}
		else
		{
			while (small-- != 0)
				ft_rotating_ra(arr, 1);
		}
		ft_pushing_pb(arr, arr1, arrlen, 1);
		small = lookforval(*arr, 0);
	}
	if (*arrlen == 3)
		sort_3(arr, arr1, arrlen);
	while (*arr1)
	{
		ft_pushing_pa(arr, arr1, arrlen, 1);
	}
}
