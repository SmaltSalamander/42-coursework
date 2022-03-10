/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:59:26 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/02/16 14:58:02 by sbienias         ###   ########.fr       */
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
# include <sys/types.h>
# include <dirent.h>

typedef struct s_data {
	char	***commands;
	int		srcin;
	int		srcout;
	int		srcerr;
	int		pipes;
	int		count;
	int		quote;
	char	*nameout;
	char	*namein;
	char	*nameerr;
	char	**paths;
	char	*limiter;
	int		here_doc_fd;
	char	**envp;
	int		exit_status;
}				t_data;

extern int	g_flag[2];
void	free_arr(char **arr);
void	execute_line(t_data *data);
int		ft_echo(char **line_split);
int		ft_cd(char **line_split, t_data data);
int		ft_pwd(char **line_split);
void	ft_export(t_data *data, char **line_split);
void	ft_unset(t_data data, char **line_split);
void	ft_env(t_data data);
void	ft_exit(t_data *data, int index);
char	*expand_variables(char *line, t_data *data);
void	parse(t_data *data, char	*line);
char	*append_char(char *line, char c);
int		arr_length(char ***arr);
void	initvals(t_data *parsed, int type);
int		ft_here_doc(t_data data);
int		open_file_write(char *filename, int mode);
void	handle_signal(int sig);
int		catch_signal(int sig, void (*handler)(int));
char	*ft_getenv(const char *name, t_data parsed);
int		redirect_input(t_data data);
void	redirect_output(t_data data);
void	pipe_last_command(int i, int *fd, t_data *data);
void	handle_pipes(int *fd, t_data *data);
void	exec_command(char **cmd_split, t_data *data);
int		execute_built_in(t_data *data, int index);
void	pipe_first_command(int *fd, t_data *data);
char	*expand_wildcard(int *i, char *new_line, char *line);
char	*expand_var(int *i, char *new_line, char *line, t_data data);
char	*expand_exit_status(int *i, char *new_line, t_data data);
char	*extract_pattern(int *i, char *line, char *new_line);
char	*get_prompt(void);
void	free_arr_arr(char ***arr);
void	clean_exit(t_data *data, int status, int flag);

//Parsing utils
int		find_if_closed(char	*line, int *isclosing, char c);
int		ft_spec_char(char c);
char	*cleanoff_trailing_whitespace(char	*str);
char	**add_to_array(char	*str, char **arr, int	*count);
char	***add_to_command(char	**arr, t_data *data);
void	add_element(char **tmp, char ***arr, int	*count, int type);
void	syntax_error_check(t_data *data);
int		flag_handling(char c, t_data *data, char **line);

//Parsing IO
void	ft_handle_input(t_data *data, char	**line, char type);
void	ft_handle_output(t_data *data, char	**line, char type);
void	ft_set_errout(t_data *data, char	**line, char type);
void	ft_here_doc_exc(t_data *data, char *c);
void	input_output(char *c, t_data *data, int inout);
void	handle_errout(char *c, t_data *data);

#endif
