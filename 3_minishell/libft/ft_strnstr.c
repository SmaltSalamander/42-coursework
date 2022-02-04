/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:09:53 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:09:53 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		counter;
	size_t		ctrneed;
	size_t		needle_ct;

	needle_ct = ft_strlen(little);
	if (needle_ct == 0)
		return ((char *)(big));
	counter = 0;
	ctrneed = 0;
	while (*(big + counter) != '\0' && counter < len)
	{
		while (*(little + ctrneed) == *(big + counter + ctrneed))
		{
			if ((counter + ctrneed) >= len)
				break ;
			if (ctrneed == needle_ct - 1)
				return ((char *)(big + counter));
			ctrneed++;
		}
		ctrneed = 0;
		counter++;
	}
	return (NULL);
}
