/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:24:45 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/13 15:34:02 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushing_pb(t_list **arr, t_list **wrkngstck, int *arrlen, int print)
{
	t_list	*ele;

	ele = *arr;
	*arr = (*arr)->next;
	ele->next = *wrkngstck;
	*wrkngstck = ele;
	*arrlen = *arrlen - 1;
	if (print)
		ft_putstr_fd("pb\n", 1);
}

void	ft_pushing_pa(t_list **arr, t_list **wrkngstck, int *arrlen, int print)
{
	t_list	*ele;

	ele = *wrkngstck;
	*wrkngstck = (*wrkngstck)->next;
	ele->next = *arr;
	*arr = ele;
	*arrlen = *arrlen + 1;
	if (print)
		ft_putstr_fd("pa\n", 1);
}
