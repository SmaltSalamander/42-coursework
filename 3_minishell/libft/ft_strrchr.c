/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:11:02 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:11:02 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = ft_strlen(s);
	if (s)
	{	
		if (*(s + counter) == '\0' && c == '\0')
			return ((char *)(s + counter));
		while (counter >= 0)
		{
			if (*(s + counter) == c)
				return ((char *)(s + counter));
			counter--;
		}
	}
	return (NULL);
}
