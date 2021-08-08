/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:57:03 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 09:57:03 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	ctr;

	ctr = 0;
	if (dest < src)
	{
		while (ctr < n)
		{
			*(char *)(dest + ctr) = *(char *)(src + ctr);
			ctr++;
		}
	}
	else
	{
		while (ctr < n)
		{
			*(char *)(dest + n - 1 - ctr) = *(char *)(src + n - 1 - ctr);
			ctr++;
		}
	}
	return (dest);
}
