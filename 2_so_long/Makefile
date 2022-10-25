# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 09:53:50 by sbienias          #+#    #+#              #
#    Updated: 2021/05/13 09:53:50 by sbienias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = main.c mapcheck.c putimg.c playermovement.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
DEPS = ft_printf.h
NAME = so_long
LIBFTPATH = ./libft
LIBRARY = libmlx.a
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
MINILIBXPATH = ./mlxlinux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -O3 -c $< -o $@

$(NAME): $(SRC)
	$(CC) $(SRC) $(LIBRARY) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFTPATH) -lft -o $(NAME)
endif

ifeq ($(UNAME), Darwin)
MINILIBXPATH = ./mlxmac

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlxmac -c $< -o $@

$(NAME): $(SRC)
	$(CC) -Lmlx -L $(MINILIBXPATH) -lmlx -framework OpenGL -framework AppKit -L $(LIBFTPATH) -lft $(SRC) -o $(NAME)
endif

all: $(LIBRARY) libft.a $(NAME)

$(LIBRARY):
	make -C $(MINILIBXPATH)
	cp $(MINILIBXPATH)/$(LIBRARY) .
	cp $(MINILIBXPATH)/mlx.h .

libft.a:
	make -C $(LIBFTPATH)

debug: $(SRC) $(TEST) $(LIBRARY)
	$(CC) -g -o a.out $(CFLAGS) $(TEST) $(SRC) $(NAME)

bonus: $(OBJSBONUS)
	$(CC) $(SRC) $(LIBRARY) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFTPATH) -lft -o $(NAME)

clean:
	/bin/rm -f $(OBJS) a.out mlx.h

fclean: clean
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C $(LIBFTPATH) fclean
	make -C $(MINILIBXPATH) clean

re: fclean all
