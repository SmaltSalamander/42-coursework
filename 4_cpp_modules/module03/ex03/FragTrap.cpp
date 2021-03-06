/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 13:39:46 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Frag's Default constructor called" << std::endl;
	this->_name = "Nameless";
	_hp = 100;
	_energ = 100;
	_attdmg = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Frag's Default constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_energ = 100;
	_attdmg = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Frag's Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ptr) : ClapTrap::ClapTrap(ptr)
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

void    FragTrap::setHitPoints()
{
	_hp = 100;
}

void    FragTrap::setAttackDamage()
{
	_attdmg = 30;
}