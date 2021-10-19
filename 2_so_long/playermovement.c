/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:55:22 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/17 18:37:32 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*find_player(int *counter, t_list *line)
{
	t_list	*curr;

	curr = line->next;
	while (curr->next)
	{
		*counter = 0;
		while (*(char *)(curr->content + *counter) != 'P' \
		&& *(char *)(curr->content + *counter))
			*counter = *counter + 1;
		if (*(char *)(curr->content + *counter) == 'P')
			break ;
		line = curr;
		curr = curr->next;
	}
	return (line);
}

char	*next_position(int dir, t_list *line, int counter)
{
	char	*currdir;

	currdir = (char *)(ft_lstlast(line)->content);
	if (dir == UP)
		currdir = (char *)(line->content + counter);
	else if (dir == LEFT)
		currdir = (char *)(line->next->content + counter - 1);
	else if (dir == RIGHT)
		currdir = (char *)(line->next->content + counter + 1);
	else if (dir == DOWN)
		currdir = (char *)(line->next->next->content + counter);
	return (currdir);
}

void	move_char(t_window *mlx, int dir)
{
	t_list	*line;
	int		counter;
	char	*currdir;

	line = find_player(&counter, (*mlx).map);
	currdir = next_position(dir, line, counter);
	if (*currdir != '1')
	{
		if (*currdir == 'C')
			(*mlx).score = (*mlx).score - 1;
		else if (*currdir == 'E' && (*mlx).score == 0)
			close_game(mlx);
		else if (*currdir == 'E')
			return ;
		*currdir = 'P';
		*(char *)(line->next->content + counter) = '0';
		(*mlx).mov_count = (*mlx).mov_count + 1;
	}
	return ;
}
