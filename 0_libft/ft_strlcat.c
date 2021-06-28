/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:08:17 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:08:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	strlendest;
	size_t	strlensrc;
	size_t	counter;

	strlendest = ft_strlen(dst);
	strlensrc = ft_strlen(src);
	if (!dst || !src)
		return (0);
	counter = 0;
	if (size <= strlendest)
		return (size + strlensrc);
	while (*(src + counter) != '\0' && (counter + strlendest) < size - 1)
	{
		*(dst + strlendest + counter) = *(src + counter);
		counter++;
	}
	*(dst + strlendest + counter) = '\0';
	if (size < strlendest)
		return (size + strlensrc);
	else
		return (strlendest + strlensrc);
}
