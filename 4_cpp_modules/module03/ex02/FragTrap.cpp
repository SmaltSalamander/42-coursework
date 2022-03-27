/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 19:47:42 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "Scav's Default constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_energ = 50;
	_attdmg = 20;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Scav's Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

FragTrap &FragTrap::operator=(FragTrap const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_name = right._name;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "Heeeeey, high fives~!" << std::endl;
}
