/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:09:34 by sbienias          #+#    #+#             */
/*   Updated: 2021/05/19 10:09:34 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ctr;

	if (n == 0)
		return (0);
	ctr = 0;
	while (ctr < n - 1)
	{
		if (*(s1 + ctr) != *(s2 + ctr))
			break ;
		if (*(s1 + ctr) == '\0')
			break ;
		ctr++;
	}
	return (*(unsigned char *)(s1 + ctr) - *(unsigned char *)(s2 + ctr));
}
