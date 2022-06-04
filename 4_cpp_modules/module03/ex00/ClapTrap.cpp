/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 12:15:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Nameless";
	_hp = 10;
	_energ = 10;
	_attdmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;
	_name = name;
	_hp = 10;
	_energ = 10;
	_attdmg = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_name = right._name;
	return (*this);
}
std::string		ClapTrap::getName()
{
	return (this->_name);
}

unsigned int	ClapTrap::getDmg()
{
	return (this->_attdmg);
}

int				ClapTrap::getHp()
{
	return (this->_hp);
}

int				ClapTrap::getEng()
{
	return (this->_energ);
}


void 			ClapTrap::setAttDmg(unsigned int  amount)
{
	this->_attdmg = amount;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0 || this->_energ <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is unable to perform actions anymore!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attdmg << " points of damage!" << std::endl;
	this->_energ -= 1;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has already been defeated!" << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " was destroyed!" << std::endl;
}
	
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0 || this->_energ <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is unable to perform actions anymore!" << std::endl;
		return ;
	}
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " was repaired for " << amount << " health points!" << std::endl;
	this->_energ -= 1;
}
