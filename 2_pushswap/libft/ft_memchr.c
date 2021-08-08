/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:55:52 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 09:55:52 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	ctr;

	ctr = 0;
	while (ctr < n)
	{
		if (*((unsigned char *)(s + ctr)) == ((unsigned char) c))
		{
			return ((void *)(s + ctr));
		}
		ctr++;
	}
	return (NULL);
}
