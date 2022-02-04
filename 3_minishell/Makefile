NAME = minishell
INCLUDES = minishell.h

W = -Wall -Werror -Wextra
SOURCE = main.c utils.c execute.c parse.c builtins_1.c builtins_2.c expand.c \
manage_terminal.c here_doc.c signals.c parse_utils.c parse_io.c \
struct_handling.c
OBJ = $(SOURCE:.c=.o)

$(NAME): $(SOURCE) libft/libft.a
	gcc $(SOURCE) -g -L ./libft -lft -lreadline -o $(NAME)

libft/libft.a:
	$(MAKE) -C libft

all: $(NAME)

clean:
	rm -f $(OBJ)

clean_all: clean clean_libft

clean_libft:
	cd libft && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C ./libft fclean

re: fclean $(NAME)

#%.o : %.c
#	gcc $(W) -g $< -c
