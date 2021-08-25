/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:24:45 by sbienias          #+#    #+#             */
/*   Updated: 2021/08/25 13:43:43 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushing_pb(t_list **arr, t_list **wrkngstck, int *arrlen)
{
	t_list	*ele;

	ele = *arr;
	ft_lstadd_front(wrkngstck, ft_lstnew(ele->content));
	*arr = (*arr)->next;
	free(ele);
	*arrlen = *arrlen - 1;
	ft_putstr_fd("pb\n", 1);
}

void	ft_pushing_pa(t_list **arr, t_list **wrkngstck, int *arrlen)
{
	t_list	*ele;

	ele = *wrkngstck;
	ft_lstadd_front(arr, ft_lstnew(ele->content));
	*wrkngstck = (*wrkngstck)->next;
	free(ele);
	*arrlen = *arrlen + 1;
	ft_putstr_fd("pa\n", 1);
}
