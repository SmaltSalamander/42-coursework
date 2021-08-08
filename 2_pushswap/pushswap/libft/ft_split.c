/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:30:47 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/20 12:30:47 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**initarray(char const *s, char c, size_t counter)
{
	size_t	arrcount;
	char	**array;

	arrcount = 1;
	if (*(s + counter) == '\0')
		arrcount = 0;
	while (*(s + counter) != '\0')
	{
		if (*(s + counter) == c && *(s + counter + 1) != '\0')
			if (*(s + counter + 1) != c)
				arrcount++;
		counter++;
	}
	array = malloc(sizeof(char **) * (arrcount + 1));
	if (!array)
		return (NULL);
	*(array + arrcount) = 0;
	return (array);
}

static char	*fillit(const char *src, size_t findex, size_t lindex)
{
	size_t	counter;
	char	*dest;

	counter = 0;
	dest = malloc(lindex - findex + 1);
	if (!dest)
		return (NULL);
	while (findex < lindex)
	{
		*(dest + counter) = *(src + findex);
		counter++;
		findex++;
	}
	*(dest + counter) = '\0';
	return (dest);
}

static size_t	searchfirstnonc(char const *s, size_t count, char c)
{
	while (*(s + count) == c && c != '\0')
	{
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	firstindex;
	size_t	counter[2];
	char	**strarray;

	if (s == NULL)
		return (NULL);
	counter[0] = 0;
	firstindex = searchfirstnonc(s, counter[0], c);
	counter[1] = 0;
	strarray = initarray(s, c, firstindex);
	if (!strarray)
		return (NULL);
	while (*(s + counter[0]) != '\0')
	{
		if (*(s + counter[0]) == c && firstindex < counter[0])
		{
			*(strarray + counter[1]) = fillit(s, firstindex, counter[0]);
			firstindex = searchfirstnonc(s, counter[0], c);
			counter[1]++;
		}
		counter[0]++;
	}
	if (firstindex < counter[0])
		*(strarray + counter[1]) = fillit(s, firstindex, counter[0]);
	return (strarray);
}
