/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:56:23 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 09:56:23 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	ctr;
	int		result;

	if (n == 0)
		return (0);
	ctr = 0;
	while (ctr < n - 1)
	{
		if (*(unsigned char *)(s1 + ctr) != *(unsigned char *)(s2 + ctr))
			break ;
		ctr++;
	}
	result = (int)(*(unsigned char *)(s1 + ctr) - *(unsigned char *)(s2 + ctr));
	return (result);
}
