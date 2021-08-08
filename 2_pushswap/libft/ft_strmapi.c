/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:30:49 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/20 12:30:49 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	strlen;
	size_t	counter;
	char	*result;

	if (!s || !f)
		return (NULL);
	strlen = ft_strlen(s);
	counter = 0;
	result = malloc(sizeof(char) * strlen + 1);
	if (result == NULL)
		return (NULL);
	while (*(s + counter) != '\0')
	{
		*(result + counter) = (*f)(counter, *(s + counter));
		counter++;
	}
	*(result + counter) = '\0';
	return (result);
}
