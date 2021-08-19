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

SRC = ft_printf.c ft_printf_util.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
MINILIBXPATH = ./minilibx_macos
DEPS = ft_printf.h
NAME = fdf
LIBRARY = libmlx.a

all: $(NAME)

$(LIBRARY):
	make -C $(LIBFTPATH)
	cp ./minilibx_macos/libmlx.a $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

olib: $(SRC) $(DEPS)
	$(CC) -c $(CFLAGS) $(SRC)

archive:
	ar rc $(NAME) $(OBJS)

debug: $(SRC) $(TEST) $(LIBRARY)
	$(CC) -g -o a.out $(CFLAGS) $(TEST) $(SRC) $(NAME)

bonus: $(OBJSBONUS)
	ar rc $(NAME) $(OBJSBONUS)

clean:
	/bin/rm -f $(OBJS) a.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(OBJSBONUS)