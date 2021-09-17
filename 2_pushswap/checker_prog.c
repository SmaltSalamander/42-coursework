/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:39:36 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/15 17:53:32 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	interpret_rotations(t_list **arr, t_list **arr1, t_list **comms)
{
	t_list	*copy;

	copy = *comms;
	if (!ft_strncmp(copy->content, "ra\0", 3))
		ft_rotating_ra(arr, 0);
	else if (!ft_strncmp(copy->content, "rb\0", 3))
		ft_rotating_rb(arr1, 0);
	else if (!ft_strncmp(copy->content, "rra\0", 4))
		ft_rev_rotating_ra(arr, 0);
	else if (!ft_strncmp(copy->content, "rrb\0", 4))
		ft_rev_rotating_rb(arr1, 0);
	else if (!ft_strncmp(copy->content, "rrr\0", 4))
	{
		ft_rev_rotating_ra(arr, 0);
		ft_rev_rotating_rb(arr1, 0);
	}
	else if (!ft_strncmp(copy->content, "rr\0", 3))
	{
		ft_rotating_ra(arr, 0);
		ft_rotating_rb(arr1, 0);
	}
	else
		return (0);
	return (1);
}

int	interpret_command(t_list **arr, t_list **arr1, t_list **comms)
{
	int		length;
	t_list	*copy;

	copy = *comms;
	length = 2;
	if (!ft_strncmp(copy->content, "sa\0", 3))
		ft_swapping(*arr, 0, 0);
	else if (!ft_strncmp(copy->content, "sb\0", 3))
		ft_swapping(0, *arr1, 0);
	else if (!ft_strncmp(copy->content, "ss\0", 3))
		ft_swapping(*arr, *arr1, 0);
	else if (!ft_strncmp(copy->content, "pa\0", 3))
		ft_pushing_pa(arr, arr1, &length, 0);
	else if (!ft_strncmp(copy->content, "pb\0", 3))
		ft_pushing_pb(arr, arr1, &length, 0);
	else
		length = interpret_rotations(arr, arr1, comms);
	*comms = (*comms)->next;
	ft_lstdelone(copy, free);
	if (length != 0 && *comms)
		interpret_command(arr, arr1, comms);
	return (length);
}

void	add_to_list(char *string, t_list **list)
{
	t_list	*element;
	char	*strcpy;

	strcpy = ft_strdup(string);
	element = ft_lstnew((char *)strcpy);
	ft_lstadd_back(list, element);
}

int	read_commands(t_list *arr)
{
	int		test;
	char	*command;
	t_list	*wrkng;
	int		len;
	t_list	*cmdlist;

	len = ft_lstsize(arr);
	wrkng = 0;
	cmdlist = 0;
	test = 1;
	while (get_next_line(0, &command))
		add_to_list(command, &cmdlist);
	if (cmdlist)
		test = interpret_command(&arr, &wrkng, &cmdlist);
	if (test == 0)
		return (1);
	test = ft_check_order(arr, len);
	if (wrkng)
		ft_lstclear(&wrkng, free);
	if (test == 0 && ft_lstsize(arr) == len)
		write(1, "OK\n", 3);
	else if (test == 1)
		write(1, "KO\n", 3);
	return (0);
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
			error = read_commands(arr);
	}
	else
		return (1);
	if (arr)
		ft_lstclear(&arr, free);
	if (!error)
		return (0);
	write(2, "Error\n", 6);
	return (1);
}
