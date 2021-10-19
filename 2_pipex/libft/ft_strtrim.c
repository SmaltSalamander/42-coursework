/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:22:40 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:22:40 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_index(char const *s1, char const *set, size_t type)
{
	size_t	setlen;
	size_t	counter;
	size_t	index;

	setlen = ft_strlen(set);
	counter = 0;
	if (type == 0)
		index = 0;
	else if (type == 1)
		index = ft_strlen(s1) - 1;
	while (counter < setlen)
	{
		if (*(s1 + index) == *(set + counter))
		{
			if (type == 0)
				index++;
			else if (type == 1)
				index--;
			counter = 0;
			continue ;
		}
		counter++;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	firstindex;
	size_t	lastindex;
	char	*result;

	if (s1 && set)
	{
		lastindex = ft_strlen(s1);
		firstindex = find_index(s1, set, 0);
		if (firstindex == lastindex)
		{
			result = malloc(1);
			*result = '\0';
			return (result);
		}
		lastindex = find_index(s1, set, 1);
		result = malloc(lastindex - firstindex + 2);
		if (!result)
			return (NULL);
		ft_strlcpy(result, (s1 + firstindex), (lastindex - firstindex + 2));
		return (result);
	}
	return (NULL);
}
