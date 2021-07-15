/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:09:54 by sbienias          #+#    #+#             */
/*   Updated: 2021/06/25 16:09:54 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*numtostr(long int number, int size, int makeunsign, int isadr)
{
	char			*string;
	unsigned int	umax;

	umax = -1;
	if (makeunsign == 1)
		number = number + umax + 1;
	if (isadr)
		ft_putstr_fd("0x", 1);
	string = ft_itoa_numsys((long unsigned int) number, size);
	return (string);
}

static int	advformats(const char **format, va_list args, char *string)
{
	int		counter;

	counter = -1;
	if (*(*format) == 'p')
		string = numtostr((long unsigned int)(va_arg(args, void *)), 16, 0, 1);
	else if (*(*format) == 'd')
		string = numtostr((long int)(va_arg(args, int)), 10, 0, 0);
	else if (*(*format) == 'u')
		string = numtostr((long unsigned int)(va_arg(args, int)), 10, 1, 0);
	else if (*(*format) == 'x')
		string = numtostr((long unsigned int)(va_arg(args, int)), 16, 1, 0);
	else if (*(*format) == 'X')
	{
		string = numtostr((long unsigned int)(va_arg(args, int)), 16, 1, 0);
		while (*(string + ++counter))
			*(string + counter) = ft_toupper(*(string + counter));
	}
	else
		return (0);
	if (string)
	{
		counter = ft_strlen(string);
		if (*(*format) == 'p')
			counter += 2;
		ft_putstr_fd(string, 1);
		free(string);
	}
	return (counter);
}

static int	printformat(const char **format, va_list args)
{
	char	*rst;
	int		strlen;

	rst = 0;
	strlen = 1;
	(*format)++;
	if (*(*format) == 'i')
		rst = ft_itoa(va_arg(args, int));
	else if (*(*format) == 'c')
	{
		ft_putchar_fd((char) va_arg(args, int), 1);
	}
	else if (*(*format) == 's')
		rst = (char *)va_arg(args, void *);
	else if (*(*format) == '%')
		ft_putchar_fd('%', 1);
	else
		return (advformats(format, args, rst));
	if (rst)
	{
		strlen = ft_strlen(rst);
		ft_putstr_fd(rst, 1);
		if (*(*format) != 's')
			free(rst);
	}
	return (strlen);
}

int	ft_printf(const char *format, ...)
{
	va_list	strings;
	int		strlen;

	va_start(strings, format);
	strlen = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			strlen++;
		}
		else
			strlen += printformat(&format, strings);
		format++;
	}
	return (strlen);
}
