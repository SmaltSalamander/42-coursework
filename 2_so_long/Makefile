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
MINILIBXPATH = ./mlx
DEPS = ft_printf.h
NAME = so_long.out
LIBRARY = libmlx.a
LIBFTPATH = ./libft
all: $(LIBRARY) libft.a $(NAME)

# Mac
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# Linux
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@
# Mac
# $(NAME): $(OBJ)
# 	$(CC) -L /usr/X11/lib -lXext -lX11 $(SRC) $(LIBRARY)
# Linux
$(NAME): $(SRC)
	$(CC) $(SRC) $(LIBRARY) -g $(CFLAGS) -L/usr/include/X11/extensions -lX11 -lXext -L $(LIBFTPATH) -lft

$(LIBRARY):
	make -C $(MINILIBXPATH)
	cp $(MINILIBXPATH)/$(LIBRARY) .

libft.a:
	make -C $(LIBFTPATH)

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
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C $(LIBFTPATH) fclean

re: fclean all
