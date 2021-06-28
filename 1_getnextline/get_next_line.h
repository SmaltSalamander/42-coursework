/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:06:40 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/12 12:06:40 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*join_strings(char *s1, char *s2);

#endif