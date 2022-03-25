/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 16:44:37 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl(void)
{
}

void    Harl::debug(void)
{
	std::cout << "Very desriptive debugging message" << std::endl;
}

void    Harl::info(void)
{
	std::cout << "You were currently in this function, or something" << std::endl;
}

void    Harl::warning(void)
{
	std::cout << "The stuff our compilation turns into errors anyway" << std::endl;
}

void    Harl::error(void)
{
	std::cout << "You done goofed up, this is an error" << std::endl;
}

void	Harl::complain(string level)
{
	std::string actions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;
	void	(Harl::*Table[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	i = 0;
	while (i < 4)
	{
		if (level == actions[i])
			(this->*Table[i])();
		i++;
	}
}
