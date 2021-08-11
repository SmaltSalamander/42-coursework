/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:09:21 by sbienias          #+#    #+#             */
/*   Updated: 2021/07/23 15:09:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_swapping(int **arr, int **wrkngstck, int *wrkbegin)
{
	int	temp;
	int initswapb;

	initswapb = 0;
	if (*wrkngstck && *wrkngstck - wrkbegin >= 2)
	{
		if (*(*wrkngstck) < *(*wrkngstck - 1))
		{
			temp = *(*wrkngstck);
			*(*wrkngstck) = *(*(wrkngstck - 1));
			*(*(wrkngstck - 1)) = temp;
			initswapb = 1;
		}
	}
	temp = **arr;
	**arr = *(*arr + 1);
	*(*arr + 1) = temp;
	if (initswapb)
		ft_putstr_fd("ss\n", 1);
	else
		ft_putstr_fd("sa\n", 1);
}

void	ft_pushing(int **arr, int **wrkngstck, int *wrkbegin, int direction)
{
	int counter;
	int	wkstcklen;

	wkstcklen = *wrkngstck - wrkbegin;
	counter = 0;
	if (direction == 0)
	{
		while (counter < wkstcklen)
		{
			*(*wrkngstck - counter + 1) = *(*wrkngstck - counter);
			counter++;
		}
		*wrkbegin = **arr;
		ft_putstr_fd("pb\n", 1);
	}
	else
	{
		*arr = (*arr - 1);
		**arr = *wrkbegin;
		while (*(wrkngstck - counter) > wrkbegin)
		{
			*(*wrkngstck - counter - 1) = *(*wrkngstck - counter);
			counter++;
		}
		**wrkngstck = 0;
		*wrkngstck = (*wrkngstck - 1);
		ft_putstr_fd("pa\n", 1);
	}
}

void	issue_commands(int **arr, int **wrkngstck, int *wrkbegin, int *arrlen)
{
	if ((**arr) > (*(*arr + 1)))
		ft_swapping(arr, wrkngstck, wrkbegin);
	else if (*wrkbegin)
	{
		if (**arr < *wrkbegin)
		{
			ft_pushing(arr, wrkngstck, wrkbegin, 1);
			*arrlen = *arrlen + 1;
		}		
	}
	else if ((**arr) < *(*arr + 1))
	{
		if (*arrlen <= 2 && *wrkbegin)
		{
			ft_pushing(arr, wrkngstck, wrkbegin, 1);
			*arrlen = *arrlen + 1;
			return ;
		}
		ft_pushing(arr, wrkngstck, wrkbegin, 0);
		*arr = (*arr + 1);
		*wrkngstck = (*wrkngstck + 1);
		*arrlen = *arrlen - 1;
	}
}
