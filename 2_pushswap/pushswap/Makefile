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

SRC = main.c commands.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Wextra
LIBPATH = ./libft
DEPS = libft.h
NAME = push_swap
LIBRARY = libft.a

all: $(NAME)

$(LIBRARY):
	make -C $(LIBPATH)

$(NAME): $(LIBRARY) $(OBJS)
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBPATH) -lft

olib: $(SRC) $(DEPS)
	$(CC) -c $(CFLAGS) $(SRC)

archive:
	ar rc $(NAME) *.o

debug: $(SRC) $(LIBRARY)
	$(CC) -g -o a.out $(CFLAGS) $(SRC) -L $(LIBPATH) -lft

bonus: $(OBJSBONUS)
	ar rc $(NAME) $(OBJSBONUS)

clean:
	/bin/rm -f *.o *.so a.out *.debug

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(OBJSBONUS)