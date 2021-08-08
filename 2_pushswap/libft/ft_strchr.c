/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:08:00 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:08:00 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		if (*(s + counter) == c)
			return ((char *)(s + counter));
		counter++;
	}
	if (*(s + counter) == '\0' && c == '\0')
		return ((char *)(s + counter));
	return (NULL);
}
