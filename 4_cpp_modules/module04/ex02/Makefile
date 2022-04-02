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

CC = c++

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g -Wshadow
NAME = animals

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

debug: $(SRC)
	$(CC) -g -o a.out $(SRC)

bonus: all

clean:
	/bin/rm -f a.out
	rm -rf $(NAME).dSYM

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
