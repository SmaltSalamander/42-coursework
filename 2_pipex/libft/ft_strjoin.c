/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:22:05 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:22:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s2len;
	size_t	s1len;
	size_t	counter;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = ft_calloc(sizeof(char), s1len + s2len + 1);
	if (str != NULL)
	{
		counter = 0;
		while (counter++ < s1len)
			*(str + counter - 1) = *(s1 + counter - 1);
		counter = 0;
		while (counter++ < s2len)
			*(str + s1len + counter - 1) = *(s2 + counter - 1);
		*(str + s1len + s2len) = '\0';
	}
	return (str);
}
