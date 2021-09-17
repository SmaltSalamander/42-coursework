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

SRC = main.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
MINILIBXPATH = ./minilbxMac
DEPS = ft_printf.h
NAME = so_long.out
LIBRARY = libmlx.a

all: $(LIBRARY) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -L /usr/X11/lib -lXext -lX11 $(SRC) $(LIBRARY)

$(LIBRARY):
	make -C $(MINILIBXPATH)
	cp $(MINILIBXPATH)/$(LIBRARY) .

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