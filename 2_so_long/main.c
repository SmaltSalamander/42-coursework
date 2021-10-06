/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:52:44 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/01 21:24:06 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilbx/mlx.h"
#include <mlx.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_data {
	void	*img;
	int		width;
	int		height;
}				t_data;

typedef struct	s_window {
	void	*mlx;
	void	*win;
	t_data	img;
	t_list	*map;
	int		score;
	int		mov_count;
}				t_window;


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
		else if (*line == '1' || *line == '0');
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
	int		strlen;
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
	if (!status || !event_count[0] || !event_count[1] || \
	event_count[2] != 1 || !read_ends(line))
		status = 1;
	else
		status = 0;
	*score = event_count[0];
	ft_lstadd_back(map, ft_lstnew(line));
	close(fd);
	return (status);
}

void	put_sprite_in_win(char type, t_window *mlx, t_data *img, int *crds)
{
	if (type == '1')
	{
		(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./wall1.xpm", \
		&(*img).width, &(*img).height);
	}
	else if (type == 'C')
	{
		(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./collect.xpm", \
		&(*img).width, &(*img).height);
	}
	else if (type == 'E')
	{
		(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./exit1.xpm", \
		&(*img).width, &(*img).height);
	}
	else if (type == 'P')
	{
		(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./wolf6.xpm", \
		&(*img).width, &(*img).height);
	}
	else
		(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./bg.xpm", \
		&(*img).width, &(*img).height);
	mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, *crds, crds[1]);
}

void draw(t_window *mlx, t_data *img, t_list *map)
{
	int		coords[2];
	int		counter;
	char	*line;
	t_list	*copy;

	counter = 0;
	coords[0] = 0;
	coords[1] = 0;
	copy = map;
	while (copy)
	{
		line = copy->content;
		while (*(line + counter))
		{
			put_sprite_in_win(*(line + counter), mlx, img, coords);
			counter++;
			coords[0] += 32;
		}
		if (counter == 0)
			break ;
		copy = copy->next;
		coords[1] += 32;
		coords[0] = 0;
		counter = 0;
	}
}

int	move_char(t_list *map, int dir, int *mov_count, int score)
{
	t_list	*prev;
	t_list	*curr;
	int		counter;
	int		retval;
	char	*currdir;

	prev = map;
	retval = 0;
	curr = prev->next;
	while (curr->next)
	{
		counter = 0;
		while (*(char *)(curr->content + counter) != 'P' \
		&& *(char *)(curr->content + counter))
			counter++;
		if (*(char *)(curr->content + counter) == 'P')
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (dir == 119)
		currdir = (char *)(prev->content + counter);
	else if (dir == 97)
		currdir = (char *)(curr->content + counter - 1);
	else if (dir == 100)
		currdir = (char *)(curr->content + counter + 1);
	else if (dir == 115)
		currdir = (char *)(curr->next->content + counter);
	if (*currdir != '1')
	{
		if (*currdir == 'C')
			retval = 1;
		else if (*currdir == 'E' && score == 0)
			exit(0);
		else if (*currdir == 'E')
			return (0);
		*currdir = 'P';
		*(char *)(curr->content + counter) = '0';
		*mov_count = *mov_count + 1;
	}
	return (retval);
}

int	catch_key(int key, t_window *mlx)
{
	if (key == 119 || key == 97 || key == 100 || key == 115)
	{
		if (move_char((*mlx).map, key, &((*mlx).mov_count), (*mlx).score))
			(*mlx).score = (*mlx).score - 1;
	}
	else if (key == 65307)
		exit(0);
	// {
	// 	if (move_char((*mlx).map, 'u', &((*mlx).mov_count)))
	// 		(*mlx).score = (*mlx).score - 1;
	// }
	// else if (key == 97)
	// {
	// 	if (move_char((*mlx).map, 'l', &((*mlx).mov_count)))
	// 		(*mlx).score = (*mlx).score - 1;
	// }
	// else if (key == 100)
	// {
	// 	if (move_char((*mlx).map, 'r', &((*mlx).mov_count)))
	// 		(*mlx).score = (*mlx).score - 1;
	// }
	// else if (key == 115)
	// {
	// 	if (move_char((*mlx).map, 'd', &((*mlx).mov_count)))
	// 		(*mlx).score = (*mlx).score - 1;
	// }

	if (key == 119 || key == 97 || key == 100 || key == 115)
		ft_putnbr_fd((*mlx).mov_count, 1);
	ft_printf("Score %d\n", (*mlx).score);
	return (0);
}

int	close_game(void *param)
{
	(void)param;
	exit(0);
}

int	render(t_window *mlx)
{
	draw(mlx, &((*mlx).img), (*mlx).map);
	return (0);
}

void	set_values(t_window *mlx, t_list *map)
{
	(*mlx).map = map;
	(*mlx).mov_count = 0;
}

int	main(int argc, char **argv)
{
	t_window	mlx;
	t_data		img;
	int			status;
	t_list		*map;

	if (argc != 2)
		return (1);
	map = 0;
	status = open(argv[1], O_RDONLY);
	if (map_error_check(status, &map,  &(mlx.score)) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, ft_strlen(map->content)*32, ft_lstsize(map)*32, "Save meee");
	set_values(&mlx, map);
	// mlx.map = map;
	// mlx.score = 0;
	draw(&mlx, &(mlx.img), mlx.map);
	mlx_key_hook(mlx.win, catch_key, (void *) &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, close_game, 0);
	mlx_loop_hook(mlx.mlx, render, (void *) &mlx);
	mlx_loop(mlx.mlx);
	if (map)
		ft_lstclear(&map, free);
	// mlx_destroy_image(mlx, img.img);
	// //mlx_destroy_window(mlx, img);
	// mlx_destroy_display(mlx);
}
