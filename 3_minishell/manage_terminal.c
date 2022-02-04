/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:50:26 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/01/19 08:50:57 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_term_vars(struct termios *standard)
{
	struct termios	info;

	tcgetattr(0, &info);
	*standard = info;
//	info.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &info);
//	tcsetattr(0, TCSANOW, standard);
}
