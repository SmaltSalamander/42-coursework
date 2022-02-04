/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:59:26 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/03 14:50:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>  /* malloc */
# include <unistd.h> /* write fork exit */
# include <fcntl.h> /* open */
# include <signal.h> /* kill */
# include <sys/wait.h>
# include <termios.h> /* tcsetattr tcgetattr*/
# include <sys/ioctl.h> /* ioctl */

typedef struct s_data {
	char	**commands;
	int		srcin;
	int		srcout;
	int		pipes;
	int		flags;
	char	*nameout;
	char	*namein;
	char	**paths;
	char	*limiter;
	int		here_doc_fd;
	char	**envp;
}				t_data;

void	free_arr(char **arr);
void	execute_line(t_data *data);
//void	execute_line(t_data data, char **envp);
void	ft_echo(char **line_split, char *line);
void	ft_cd(char **line_split, t_data data);
void	ft_pwd(char **line_split, char *envp[]);
void	ft_export(t_data *data, char **line_split);
void	ft_unset(t_data data, char **line_split);
void	ft_env(t_data data);
void	ft_exit(char **line_split);
char	*expand_variables(char *line, char *envp[]);
void	parse(t_data *data, char	*line);
char	*append_char(char *line, char c);
int		arr_length(char **arr);
void	initvals(t_data *parsed, int type);
void	set_term_vars(struct termios *standard);
int		ft_here_doc(t_data data);
int		open_file_write(char *filename);
char	**add_to_array(char	*str, char **arr, int	*count);
void	handle_signal(int sig);
int		catch_signal(int sig, void (*handler)(int));
char	*ft_getenv(const char *name, t_data parsed);

//Parsing utils
int		find_if_closed(char	*line, int *isclosing);
int		ft_spec_char(char c);
char	*cleanoff_trailing_whitespace(char	*str);
char	**add_to_array(char	*str, char **arr, int	*count);

//Parsing IO
int		ft_handle_input(t_data *data, char	**line, char type);
int		ft_handle_output(t_data *data, char	**line, char type);
int		check_limiter(int	*temp_fds, t_data *data);
void	ft_here_doc_exc(t_data *data, char *c);
void	input_output(char *c, t_data *data, int inout);

#endif
