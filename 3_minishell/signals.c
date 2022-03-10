/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserdyuk <aserdyuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:13:43 by aserdyuk          #+#    #+#             */
/*   Updated: 2022/01/30 11:13:52 by aserdyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_flag[1] = 1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}

int	catch_signal(int sig, void (*handler)(int))
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, sig);
	action.sa_handler = handler;
	action.sa_flags = 0;
	return (sigaction(sig, &action, NULL));
}
