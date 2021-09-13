/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:36:45 by sbienias          #+#    #+#             */
/*   Updated: 2021/07/22 12:36:45 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

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
			ft_sort(&arr, (argc - 1));
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
