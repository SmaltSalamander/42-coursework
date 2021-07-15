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

static int	count_size(long num, int numsys)
{
	int		size;

	size = 1;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num >= numsys)
	{
		num /= numsys;
		size++;
	}
	return (size);
}

char	*ft_itoa_numsys(long num, int numsys)
{
	int		size;
	char	*result;

	size = count_size(num, numsys);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		*(result) = '-';
		num *= -1;
	}
	*(result + size) = '\0';
	while (size != 0)
	{
		if (num % numsys <= 9)
			*(result + size - 1) = (num % numsys) + '0';
		else
			*(result + size - 1) = (num % numsys) + 'a' - 10;
		num /= numsys;
		size--;
		if (num == num / numsys)
			break ;
	}
	return (result);
}

// #include "stdio.h"
// int main(void)
// {
// 	printf("%s\n", (ft_itoa_numsys(8, 8)));
// }