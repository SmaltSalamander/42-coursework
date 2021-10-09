/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:06:40 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/12 12:06:40 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	int		width;
	int		height;
}				t_data;

typedef struct s_window {
	void	*mlx;
	void	*win;
	t_data	img;
	t_list	*map;
	int		score;
	int		mov_count;
}				t_window;

int		map_error_check(int fd, t_list **map, int *score);
void	draw(t_window *mlx, t_list *map, int dir);
void	move_char(t_window *mlx, int dir);
int		close_game(t_window *mlx);

#endif