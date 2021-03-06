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
# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# ifdef __linux__
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ESC 65307
# elif __APPLE__
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ESC 53
# endif

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

int		map_error_check(char *pthname, int fd, t_list **map, int *score);
void	draw(t_window *mlx, t_list *map, int dir);
void	move_char(t_window *mlx, int dir);
int		close_game(t_window *mlx);

#endif