/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:08:34 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:08:34 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	strlen;
	size_t	srclen;

	strlen = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (*(src + strlen) != '\0' && strlen < size - 1)
	{
		*(dst + strlen) = *(src + strlen);
		strlen++;
	}
	if (strlen <= size)
	{
		*(dst + strlen) = '\0';
	}
	size = strlen;
	if (srclen > strlen)
		return (srclen);
	return (size);
}
