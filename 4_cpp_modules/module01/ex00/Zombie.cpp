/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/15 15:26:26 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << getName() << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(string name)
{
	this->_name = name;
}

string	Zombie::getName(void)
{
	return (this->_name);
}
