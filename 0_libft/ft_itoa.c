/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:30:36 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/20 12:30:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int num)
{
	int	size;

	size = 1;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	if (num == -2147483648)
		size = 11;
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = count_size(n);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
		*(result) = '-';
	*(result + size) = '\0';
	while (size != 0)
	{
		if (n % 10 < 0)
			*(result + size - 1) = -(n % 10) + '0';
		else
			*(result + size - 1) = (n % 10) + '0';
		n /= 10;
		size--;
		if (n == n / 10)
			break ;
	}
	return (result);
}
