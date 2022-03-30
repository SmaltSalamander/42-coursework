/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:25:34 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Nameless";
	_hp = 100;
	_energ = 50;
	_attdmg = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Scav's Default constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_energ = 50;
	_attdmg = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Scav's Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_name = right._name;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode now!" << std::endl;
}
