cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_STANDARD 99)

set(LIBFT_FILES
        libft/ft_split.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_memcmp.c
        libft/ft_strdup.c
        libft/ft_strchr.c
        libft/ft_memchr.c
        libft/ft_putstr_fd.c
        libft/ft_putchar_fd.c
        libft/ft_memcpy.c
        libft/ft_calloc.c
        libft/ft_substr.c
        libft/ft_memmove.c
        libft/ft_bzero.c
        libft/ft_memset.c
        libft/ft_get_next_line.c
        )

set(SOURCE_FILES
        main.c
        parse.c
        execute.c
        builtins_1.c
        builtins_2.c
        expand.c
        utils.c
        manage_terminal.c
        here_doc.c
        signals.c
        )

add_executable(minishell ${SOURCE_FILES} ${LIBFT_FILES})

target_link_libraries(minishell readline)