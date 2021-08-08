/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:22:05 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:22:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s2len;
	size_t	s1len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = s1len + ft_strlen(s2);
	str = ft_calloc(sizeof(char), s1len + s2len + 1);
	if (str != NULL)
	{
		ft_memcpy(str, s1, s1len);
		ft_memcpy((str + s1len), s2, s2len - 1);
		*(str + s1len + s2len) = '\0';
	}
	return (str);
}

// void	main(void)
// {
// 	char	*string;
// 	char	*temp;

// 	string = ft_strdup("0");
// 	temp = ft_strjoin("0x", string);
// 	ft_putstr_fd(temp, 1);
// 	free(string);
// 	free(temp);
// }
