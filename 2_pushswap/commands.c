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
	if (wrkngstck->content && ft_lstsize(wrkngstck) > 1)
	{
		if (*(int *) wrkngstck->content < *(int *) (wrkngstck->next)->content)
		{
			temp = *(int *) wrkngstck->content;
			*(int *) wrkngstck->content = *(int *) (wrkngstck->next)->content;
			*(int *) (wrkngstck->next)->content = temp;
			initswapb = 1;
		}
	}
	temp = *(int *) arr->content;
	*(int *) arr->content = *(int *) (arr->next)->content;
	*(int *) (arr->next)->content = temp;
	if (initswapb)
		ft_putstr_fd("ss\n", 1);
	else
		ft_putstr_fd("sa\n", 1);
}

void	ft_pushing_pb(t_list *arr, t_list **wrkngstck)
{
	ft_lstadd_front(wrkngstck, arr);
	*arr = *arr->next;
	ft_putstr_fd("pb\n", 1);
}

void	ft_pushing_pa(t_list **arr, t_list *wrkngstck)
{
	ft_lstadd_front(arr, wrkngstck);
	*wrkngstck = *wrkngstck->next;
	ft_putstr_fd("pa\n", 1);
}

// void	ft_rotating(int *arr, int **wrkngstck, int *wrkbegin, int *arrlen)
// {
// 	int	counter;
// 	int	wkstcklen;
// 	int temp;

// 	counter = 0;	 	
// 	temp = **arr;
// 	**arr = *(*arr + 1);
// 	*(*arr + 1) = temp;
// 	while (counter < arrlen)
// 	{
// 		*(arr + counter) = *(arr + counter + 1);
// 		counter++;
// 	}
// 	ft_putstr_fd("ra\n", 1);
// }

void	issue_commands(t_list *arr, t_list	*wrkngstck, int *arrlen)
{
	t_list	*check1;

	check1 = arr->next;
	if ((*(int *)(arr)->content) > *(int *) check1->content)
		ft_swapping(arr, wrkngstck);
	else if ((*(int *)(arr)->content) < *(int *) check1->content)
	{
		if (*(int *) wrkngstck->content)
		{
			ft_pushing_pa(&arr, wrkngstck);
			*arrlen = *arrlen + 1;
			return ;
		}
		while (((*(int *)(arr)->content) < *(int *) check1->content) && *arrlen > 2)
		{
			ft_pushing_pb(arr, &wrkngstck);
			*arrlen = *arrlen - 1;
		}
	}
}

char	ft_sort(t_list **arr, int arrlen)
{
	t_list	*workingstack;
	int	lencpy;

	lencpy = arrlen;
	workingstack = ft_lstnew(ft_calloc(1, 1));
	while (ft_check_order(*arr, lencpy) || *(int *)workingstack->content)
	{
		issue_commands(*arr, workingstack, &lencpy);
	}
	// if (workingstack)
	// 	ft_lstclear(&workingstack, free);
	return (0);
}
