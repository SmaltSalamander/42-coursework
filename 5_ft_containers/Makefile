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
CFLAGS		= -Wall -Wextra -Werror
SRCD		= ./srcs/

SRC			=	main.cpp vector.tpp
SRCF		= $(addprefix $(SRCD),$(SRC))

OBJD		= ./objs/
OBJF		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD		= $(OBJF:$(OBJD)%.o)

NAME		= ft_containers
HEADD		= ./includes/
HEADF		= vector.hpp


$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	${OBJF}
			$(CC) $(CFLAGS) $(SRCF) -I$(HEADD) -o $(NAME)

all:		${NAME}

clean:
	/bin/rm -f a.out ${OBJD}*.o
	rm -rf $(NAME).dSYM

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re