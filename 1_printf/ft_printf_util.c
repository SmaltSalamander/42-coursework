/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:57:41 by sbienias          #+#    #+#             */
/*   Updated: 2021/08/06 11:57:41 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*itoa_unsign(unsigned long num)
{
	int				size;
	char			*result;
	unsigned long	numcpy;

	size = 1;
	numcpy = num;
	while (numcpy >= 16)
	{
		numcpy /= 16;
		size++;
	}
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	*(result + size) = '\0';
	while (size != 0)
	{
		if (num % 16 <= 9)
			*(result + size - 1) = (num % 16) + '0';
		else
			*(result + size - 1) = (num % 16) + 'a' - 10;
		num /= 16;
		size--;
	}
	return (result);
}
