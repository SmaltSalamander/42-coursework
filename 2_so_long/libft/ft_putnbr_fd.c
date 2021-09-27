/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:30:42 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/20 12:30:42 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	temp_num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 0 && n < 10)
	{
		temp_num = n + '0';
		write(fd, &temp_num, 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		temp_num = n % 10 + '0';
		write(fd, &temp_num, 1);
	}
}
