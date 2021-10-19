/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:21:46 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:21:46 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	counter;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	counter = 0;
	if (start >= strlen)
		len = 0;
	else if ((start + len) > strlen)
		len = strlen - start;
	substr = malloc(len + 1);
	if (substr != NULL)
	{
		while (counter < len && *(s + start + counter) != '\0')
		{
			*(substr + counter) = *(s + start + counter);
			counter++;
		}
		*(substr + counter) = '\0';
	}
	return (substr);
}
