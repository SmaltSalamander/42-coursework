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
#include "pushswap.h"

void	ft_swapping(int **arr, int **wrkngstck, int *wrkbegin)
{
	int	temp;
	int	initswapb;

	initswapb = 0;
	if (*wrkngstck && (*wrkngstck - wrkbegin) > 0)
	{
		if (*wrkbegin < *(wrkbegin + 1))
		{
			temp = *wrkbegin;
			*wrkbegin = *(wrkbegin + 1);
			*(wrkbegin + 1) = temp;
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

void	ft_pushing_pb(int **arr, int **wrkngstck, int *wrkbegin)
{
	int	counter;
	int	wkstcklen;

	wkstcklen = *wrkngstck - wrkbegin;
	counter = wkstcklen;
	*wrkngstck = (*wrkngstck + 1);
	while (counter > 0)
	{
		*(wrkbegin + counter) = *(wrkbegin + counter - 1);
		counter--;
	}
	*wrkbegin = **arr;
	*arr = (*arr + 1);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pushing_pa(int **arr, int **wrkngstck, int *wrkbegin)
{
	int	counter;
	int	wkstcklen;

	wkstcklen = *wrkngstck - wrkbegin;
	counter = 0;
	*arr = (*arr - 1);
	**arr = *wrkbegin;
	while (counter < wkstcklen)
	{
		*(wrkbegin + counter) = *(wrkbegin + counter + 1);
		counter++;
	}
	*wrkngstck = (*wrkngstck - 1);
	ft_putstr_fd("pa\n", 1);
}

void	issue_commands(int **arr, int **wrkngstck, int *wrkbegin, int *arrlen)
{
	if ((**arr) > (*(*arr + 1)))
		ft_swapping(arr, wrkngstck, wrkbegin);
	else if ((**arr) < *(*arr + 1))
	{
		if (*wrkbegin)
		{
			ft_pushing_pa(arr, wrkngstck, wrkbegin);
			*arrlen = *arrlen + 1;
			return ;
		}
		while ((**arr) < *(*arr + 1) && *arrlen > 2)
		{
			ft_pushing_pb(arr, wrkngstck, wrkbegin);
			*arrlen = *arrlen - 1;
		}
	}
}

char	ft_sort(int *arr, int arrlen)
{
	int	*workingstack;
	int	*wrkstckstart;
	int	lencpy;

	lencpy = arrlen;
	workingstack = ft_calloc(arrlen, sizeof(int));
	if (!workingstack)
		return (1);
	wrkstckstart = workingstack;
	while (ft_check_order(arr, lencpy) || *wrkstckstart)
	{
		issue_commands(&arr, &workingstack, wrkstckstart, &lencpy);
	}
	return (0);
}
