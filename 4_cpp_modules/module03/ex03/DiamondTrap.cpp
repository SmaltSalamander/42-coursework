/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 13:41:28 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Diamond's Default constructor called" << std::endl;
	this->_name = "Nameless";
	this->ClapTrap::_name = "Nameless_clap_name";
	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Diamond's Default constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond's Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ptr) : ClapTrap::ClapTrap(ptr), FragTrap::FragTrap(ptr), ScavTrap::ScavTrap(ptr)
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

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void  DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << ", my clap name is " << this->ClapTrap::_name << std::endl;
}