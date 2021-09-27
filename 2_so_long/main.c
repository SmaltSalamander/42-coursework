/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:52:44 by sbienias          #+#    #+#             */
/*   Updated: 2021/09/27 21:57:35 by sbienias         ###   ########.fr       */
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

int	map_error_check(int fd, t_list **map)
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
	ft_lstadd_back(map, ft_lstnew(line));
	close(fd);
	return (status);
}

void draw(t_window *mlx, t_data *img, t_list *map)
{
	int		x;
	int		y;
	int		counter;
	char	*line;

	counter = 0;
	x = 0;
	y = 0;
	while (map)
	{
		line = map->content;
		while (*(line + counter))
		{
			(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./bg.xpm", &(*img).width, &(*img).height);
			mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, x, y);
			if (*(line + counter) == '1')
			{
				(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./wall1.xpm", &(*img).width, &(*img).height);
				mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, x, y);
			}
			else if (*(line + counter) == 'C')
			{
				(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./collect.xpm", &(*img).width, &(*img).height);
				mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, x, y);
			}
			else if (*(line + counter) == 'E')
			{
				(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./exit1.xpm", &(*img).width, &(*img).height);
				mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, x, y);
			}
			else if (*(line + counter) == 'P')
			{
				(*img).img = mlx_xpm_file_to_image((*mlx).mlx, "./wolf6.xpm", &(*img).width, &(*img).height);
				mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*img).img, x, y);
			}
			counter++;
			x += 32;
		}
		if (counter == 0)
			break ;
		map = map->next;
		y += 32;
		x = 0;
		counter = 0;
	}
	ft_printf("out\n");
}

int	catch_key(int key, t_list *map)
{
	t_list *prev;
	t_list *curr;
	int	counter;

	prev = *map;
	curr = prev->next;
	while (curr->next)
	{
		counter = 0;
		while (*(char *)(curr->content + counter) != 'P' && *(char *)curr->content)
			counter++;
		if (*(char *)(curr->content + counter) == 'P')
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (key == 119)
	{
		ft_putchar_fd('u', 1);
		if (*(char *)(prev->content + counter) != '1')
		{
			*(char *)(prev->content + counter) = 'P';
			*(char *)(curr->content + counter) = '0';
		}
	}
	else if (key == 97)
	{
		ft_putchar_fd('l', 1);
	}
	else if (key == 100)
	{
		ft_putchar_fd('r', 1);
	}
	else if (key == 115)
	{
		ft_putchar_fd('d', 1);
	}
	else if (key == 65307)
		exit(0);
	else
		return (0);
}

int	close_game(void *param)
{
	(void)param;
	exit(0);
}



int	render(t_window mlx)
{
	draw(&mlx, &(mlx.img), mlx.map);
	sleep(1);
	return (0);
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
	if (map_error_check(status, &map) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, ft_strlen(map->content)*32, ft_lstsize(map)*32, "Save meee");
	mlx.map = map;
	draw(&mlx, &(mlx.img), mlx.map);
	// img.img = mlx_new_image(mlx.mlx, 800, 600);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	// &img.line_length, &img.endian);

	
	mlx_key_hook(mlx.win, catch_key, &map);
	mlx_hook(mlx.win, 17, 1L << 17, close_game, 0);
	mlx_loop_hook(mlx.mlx, render, (void *) &mlx);
	mlx_loop(mlx.mlx);
	if (map)
		ft_lstclear(&map, free);
	// mlx_destroy_image(mlx, img.img);
	// //mlx_destroy_window(mlx, img);
	// mlx_destroy_display(mlx);
}
