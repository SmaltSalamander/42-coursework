/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:38:34 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/31 19:22:27 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*set_p_direction(t_window *mlx, int dir)
{
	if (dir == UP)
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wolf8.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	else if (dir == DOWN)
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wolf4.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	else if (dir == LEFT)
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wolf2.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	else
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wolf6.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	return ((*mlx).img.img);
}

void	put_sprite_in_win(char type, t_window *mlx, int *crds, int dir)
{
	if (type == '1')
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wall1.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	else if (type == 'C')
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/bg.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
		mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*mlx).img.img, \
		*crds, crds[1]);
		mlx_destroy_image((*mlx).mlx, (*mlx).img.img);
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, \
		"./img/collect.xpm", &((*mlx).img.width), &((*mlx).img.height));
	}
	else if (type == 'E')
	{
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/exit1.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	}
	else if (type == 'P')
		(*mlx).img.img = set_p_direction(mlx, dir);
	else
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/bg.xpm", \
		&((*mlx).img.width), &((*mlx).img.height));
	mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*mlx).img.img, \
	*crds, crds[1]);
	mlx_destroy_image((*mlx).mlx, (*mlx).img.img);
}

void	draw(t_window *mlx, t_list *map, int dir)
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
			put_sprite_in_win(*(line + counter), mlx, coords, dir);
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
