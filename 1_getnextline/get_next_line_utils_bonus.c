/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:27:14 by sbienias          #+#    #+#             */
/*   Updated: 2021/06/03 11:27:14 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

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
	substr = ft_calloc(1, len + 1);
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

unsigned long	ft_strlen(const char *s)
{
	unsigned long	counter;

	counter = 0;
	while (*(s + counter) != '\0')
		counter++;
	return (counter);
}

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

char	*ft_strdup(char *s)
{
	unsigned long	strlen;
	unsigned long	counter;
	char			*copy;

	strlen = ft_strlen(s);
	copy = ft_calloc(1, strlen + 1);
	counter = 0;
	if (copy == NULL)
		return (NULL);
	while (*(s + counter) != '\0')
	{
		*(copy + counter) = *(s + counter);
		counter++;
	}
	*(copy + counter) = '\0';
	return (copy);
}

char	*join_strings(char *s1, char *s2)
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
	free(s1);
	return (str);
}
