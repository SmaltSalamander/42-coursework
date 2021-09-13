/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:39:36 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/13 19:14:50 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	interpret_command(t_list **arr, t_list **arr1, char *com)
{
	int	length;

	length = 0;
	if (!ft_strncmp(com, "sa", 2))
		ft_swapping(*arr, 0, 0);
	else if (!ft_strncmp(com, "sb", 2))
		ft_swapping(0, *arr1, 0);
	else if (!ft_strncmp(com, "sa", 2))
		ft_swapping(*arr, *arr1, 0);
	else if (!ft_strncmp(com, "ra", 2))
		ft_rotating_ra(arr, 0);
	else if (!ft_strncmp(com, "rb", 2))
		ft_rotating_rb(arr1, 0);
	else if (!ft_strncmp(com, "rra", 3))
		ft_rev_rotating_ra(arr, 0);
	else if (!ft_strncmp(com, "rrb", 3))
		ft_rev_rotating_rb(arr1, 0);
	else if (!ft_strncmp(com, "pa", 2))
		ft_pushing_pa(arr, arr1, &length, 0);
	else if (!ft_strncmp(com, "pb", 2))
		ft_pushing_pb(arr, arr1, &length, 0);
	else
		return (0);
	return (1);
}

void	read_commands(t_list *arr)
{
	int		test;
	char	*command;
	t_list	*wrkng;
	int		len;
	int		command_flow;

	len = ft_lstsize(arr);
	wrkng = 0;
	test = get_next_line(0, &command);
	while (test)
	{
		command_flow = interpret_command(&arr, &wrkng, command);
		if (!command_flow)
		{
			write(2, "Error\n", 6);
			return ;
		}
		test = get_next_line(0, &command);
	}
	test = ft_check_order(arr, len);
	if (wrkng)
		ft_lstclear(&wrkng, free);
	if (test == 0 && ft_lstsize(arr) == len)
		write(1, "OK\n", 3);
	else if (test == 1)
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		error;
	int		counter;
	t_list	*arr;

	counter = -1;
	error = 0;
	arr = 0;
	if (argc > 1)
	{
		while (++counter < (argc - 1) && error != 1)
			error = ft_add_to_array(*(argv + 1 + counter), &arr);
		if (error == 0)
			error = dup_check(arr);
		if (error == 0)
			read_commands(arr);
	}
	else
		error = 1;
	if (arr)
		ft_lstclear(&arr, free);
	if (!error)
		return (0);
	write(2, "Error\n", 6);
	return (1);
}