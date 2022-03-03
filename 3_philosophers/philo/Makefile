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

SRC = main.c ft_atoi.c actions.c time_mgmt.c

#BONUS =

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = philo

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -pthread -o $(NAME)

debug: $(SRC)
	$(CC) -g -o a.out $(SRC) -pthread

bonus: all

clean:
	/bin/rm -f $(OBJS) a.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
