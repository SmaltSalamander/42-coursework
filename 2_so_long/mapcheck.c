/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:01 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/09 18:00:03 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_ends(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	read_middle(char *line, int *events)
{
	if (*line != '1')
		return (0);
	line++;
	while (*line)
	{
		if (*line == 'C')
			events[0]++;
		else if (*line == 'E')
			events[1]++;
		else if (*line == 'P')
			events[2]++;
		else if (*line == '1' || *line == '0')
			;
		else
			return (0);
		line++;
	}
	if (*(line - 1) != '1')
		return (0);
	return (1);
}

int	map_error_check(int fd, t_list **map, int *score)
{
	char	*line;
	int		status;
	int		event_count[3];

	if (fd <= 0)
		return (1);
	status = get_next_line(fd, &line);
	if (!status)
		return (1);
	status = read_ends(line);
	ft_lstadd_back(map, ft_lstnew(line));
	ft_bzero(event_count, 3 * sizeof(int));
	while (get_next_line(fd, &line) && status)
	{
		status = read_middle(line, event_count);
		ft_lstadd_back(map, ft_lstnew(line));
	}
	close(fd);
	if (!status || !event_count[0] || !event_count[1] || \
	event_count[2] != 1 || !read_ends(line))
		return (1);
	*score = event_count[0];
	ft_lstadd_back(map, ft_lstnew(line));
	return (0);
}
