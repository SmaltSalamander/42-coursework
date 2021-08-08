/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:11:17 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/25 09:11:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*element;

	if (lst == NULL)
		return (NULL);
	newlst = NULL;
	element = NULL;
	while (lst != NULL)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&newlst, del);
			free(newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, element);
		lst = lst->next;
	}
	return (newlst);
}
