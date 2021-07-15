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

SRC = ft_printf.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
LIBFTPATH = ./libft
DEPS = libftprintf.h
NAME = libftprintf.a

all: lib $(NAME)

lib:
	make -C $(LIBFTPATH)
	cp ./libft/libft.a $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

olib: $(SRC) $(DEPS)
	$(CC) -c $(CFLAGS) $(SRC)

archive:
	ar rc $(NAME) *.o

debug: $(SRC) $(TEST) lib
	$(CC) -g -o a.out $(CFLAGS) $(TEST) $(SRC) $(NAME)

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