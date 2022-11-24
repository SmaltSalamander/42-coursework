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

SRC = main.c commands.c pushing.c rotation.c sort_small.c search_median.c \
swapping.c array_manipulation.c

BONUS = checker_prog.c array_manipulation.c pushing.c rotation.c swapping.c

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBPATH = ./libft
NAME = push_swap
LIBRARY = libft.a
BSNAME = checker

all: $(LIBRARY) $(NAME)

bonus: $(LIBRARY) $(BSNAME)

$(LIBRARY):
	make -C $(LIBPATH)

$(NAME): $(SRC) 
	$(CC) -g $(CFLAGS) -o $(NAME) $(SRC) -L $(LIBPATH) -lft

debug: $(SRC) $(LIBRARY)
	$(CC) -g -o a.out $(CFLAGS) $(SRC) -L $(LIBPATH) -lft

$(BSNAME): $(BONUS) 
	$(CC) $(CFLAGS) -o $(BSNAME) $(BONUS) -L $(LIBPATH) -lft

clean:
	/bin/rm -fr $(OBJS) $(OBJSBONUS) a.out ./a.out.dSYM

fclean: clean
	/bin/rm -f $(NAME) $(BSNAME)

re: fclean all

docker:
	git -C .. submodule update --init --recursive --depth 1
	docker build -t visualizer ./dockerized_visualizer
	docker run -tiv $$(pwd):/push_swap visualizer