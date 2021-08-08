/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:13:41 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:13:41 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	strlen;
	size_t	counter;
	char	*copy;

	strlen = ft_strlen(s);
	copy = malloc(strlen + 1);
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
