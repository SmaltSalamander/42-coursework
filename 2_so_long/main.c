/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:52:44 by sbienias          #+#    #+#             */
/*   Updated: 2021/10/09 20:17:12 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_window *mlx)
{
	if ((*mlx).map)
		ft_lstclear(&(*mlx).map, free);
	mlx_destroy_window((*mlx).mlx, (*mlx).win);
	mlx_destroy_display((*mlx).mlx);
	free((*mlx).mlx);
	exit(0);
}

int	catch_key(int key, t_window *mlx)
{
	if (key == 119 || key == 97 || key == 100 || key == 115)
	{
		move_char(mlx, key);
		draw(mlx, (*mlx).map, key);
	}
	else if (key == 65307)
		close_game(mlx);
	return (0);
}

int	render(t_window *mlx)
{
	char	*movcount;
	int		len;

	len = ft_strlen((*mlx).map->content) * 32;
	movcount = ft_itoa((*mlx).mov_count);
	mlx_string_put((*mlx).mlx, (*mlx).win, len - 30, 20, 0xFFFFFF, movcount);
	free(movcount);
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	mlx;
	int			status;

	if (argc != 2)
		return (1);
	mlx.map = 0;
	status = open(argv[1], O_RDONLY);
	if (map_error_check(status, &(mlx.map), &(mlx.score)) == 1)
	{
		ft_lstclear(&(mlx.map), free);
		ft_printf("Error\n");
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, ft_strlen(mlx.map->content) * 32, \
	ft_lstsize(mlx.map) * 32, "so long");
	mlx.mov_count = 0;
	draw(&mlx, mlx.map, 0);
	mlx_key_hook(mlx.win, catch_key, (void *) &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, close_game, &mlx);
	mlx_loop_hook(mlx.mlx, render, (void *) &mlx);
	mlx_loop(mlx.mlx);
}
