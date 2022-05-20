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

SRC = main.c utils.c

#BONUS =

OBJS = $(SRC:%.c=%.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIBFTPATH = ./libft
LIBRARY = libft.a
HEADER		=	pipex.h

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make -C $(LIBFTPATH)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(HEADER) -L $(LIBFTPATH)/$(LIBRARY) -lft -o $(NAME)
#$(CC) -g $(CFLAGS) $(OBJS) -L $(LIBFTPATH) -lft -o $(NAME)

debug: $(SRC) $(TEST) $(LIBRARY)
	$(CC) -g -o a.out $(CFLAGS) $(TEST) $(SRC) $(NAME)

bonus: all

clean:
	/bin/rm -f $(OBJS) a.out mlx.h

fclean: clean
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C $(LIBFTPATH) fclean

re: fclean all
