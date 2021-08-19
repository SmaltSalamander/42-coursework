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

SRC = ft_calloc.c ft_isascii.c ft_itoa.c ft_memcmp.c ft_memset.c \
ft_putnbr_fd.c ft_strjoin.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_atoi.c \
ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c ft_strchr.c \
ft_strlcat.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_bzero.c ft_isalpha.c \
ft_isprint.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_strdup.c \
ft_strlcpy.c ft_strnstr.c ft_substr.c ft_putstr_fd.c ft_split.c ft_strmapi.c \
ft_itoa_numsys.c ft_printf_util.c ft_printf.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstdelone.c \
ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstiter.c ft_lstclear.c \
ft_lstmap.c

OBJS = $(SRC:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)
TEST = test.c
CFLAGS = -Wall -Werror -Wextra
DEPS = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(OBJSBONUS)
	ar rc $(NAME) $(OBJS) $(OBJSBONUS)

debug: $(SRC) $(TEST)
	$(CC) -g -o $(NAME).debug $(CFLAGS) $(TEST) $(SRC) -lbsd

clean:
	/bin/rm -f $(OBJS) $(OBJSBONUS) *.so a.out *.debug

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(OBJSBONUS)