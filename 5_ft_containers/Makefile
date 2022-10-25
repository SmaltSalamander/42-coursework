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

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -g -std=c++98
SRCD		= ./srcs/

SRC			=	main.cpp
SRCF		= $(addprefix $(SRCD),$(SRC))

OBJD		= ./objs/
OBJF		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD		= $(OBJF:$(OBJD)%.o)

NAME		= ft_containers
HEADD		= ./includes/
HEADF		= vector.hpp vector.tpp iterator_v.hpp features.hpp \
			pair.hpp pair.tpp map.hpp map.tpp iterator_m.hpp iterator.hpp \
			rev_iterator.hpp stack.hpp stack.tpp

SEED		= vmspseeed

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	${OBJF} $(addprefix $(HEADD),$(HEADF))
			$(CC) $(CFLAGS) $(SRCF) -I$(HEADD) -o $(NAME)
			$(CC) $(CFLAGS) $(SRCF) -I$(HEADD) -D STD -o STD$(NAME)

# Compile intra main
intra:	${OBJF} $(addprefix $(HEADD),$(HEADF))
			$(CC) $(CFLAGS) ./srcs/main2.cpp -I$(HEADD) -o $(NAME)
			$(CC) $(CFLAGS) ./srcs/main2.cpp -I$(HEADD) -D STD -o STD$(NAME)

# Compile just the STD
org:
	$(CC) $(CFLAGS) $(SRCF) -I$(HEADD) -D STD -o STD$(NAME)

# Make a file with differences between outputs, named test
check:
	./$(NAME) > res_ft && ./STD$(NAME) > res_std
	diff res_ft res_std > test || exit 0
	rm res_ft res_std

#Make a file for side by side comparison
comp:
	./$(NAME) > res_ft && ./STD$(NAME) > res_std
	diff -y res_ft res_std > test || exit 0

timed:
	time ./$(NAME) $(SEED) > res_ft
	time ./STD$(NAME) $(SEED) > res_std
	diff -y res_ft res_std > test || exit 0
	rm res_ft res_std

all:		${NAME}

clean:
	/bin/rm -f a.out ${OBJD}*.o STD$(NAME) test res_ft res_std
	rm -rf $(NAME).dSYM STD$(NAME).dSYM

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re