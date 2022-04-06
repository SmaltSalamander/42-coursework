/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:05:45 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 15:05:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::~Character(void)
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i] != NULL)
			delete _inv[i];
	}
}

Character::Character(const Character &ptr)
{
	std::cout << "Character's copy constructor called" << std::endl;
	*this = ptr;
}

Character &Character::operator=(Character const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
		if (right->_inv[i])
			this->_inv[i] = right->_inv[i].clone();
	}
	return (*this);
}

void    Character::makeSound() const
{
	std::cout << this->type << " cries" << std::endl;	
}

std::string const &  Character::getType() const
{
	return (type);
}

// std::ostream &operator<<(std::ostream &outstrobj, Character const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
