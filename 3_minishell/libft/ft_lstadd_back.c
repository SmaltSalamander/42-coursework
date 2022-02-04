/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:11:04 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/25 09:11:04 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastel;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		lastel = ft_lstlast(*lst);
		lastel->next = new;
	}
}
