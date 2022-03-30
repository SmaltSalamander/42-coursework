/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:49:39 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Nameless";
	FragTrap::_hp;
	ScavTrap::_energ;
	ScavTrap::_attdmg;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Scav's Default constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap(setAttDmg);
	ScavTrap::_energ;
	ScavTrap::_attdmg;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Scav's Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_name = right._name;
	return (*this);
}
