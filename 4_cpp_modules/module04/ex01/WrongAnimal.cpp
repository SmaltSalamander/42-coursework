/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/23 09:40:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ptr)
{
	std::cout << "WrongAnimal's copy constructor called" << std::endl;
	*this = ptr;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->type = right.type;
	return (*this);
}

void    WrongAnimal::makeSound() const
{
	std::cout << this->type << " cries" << std::endl;	
}

std::string     WrongAnimal::getType() const
{
	return (type);
}

// std::ostream &operator<<(std::ostream &outstrobj, WrongAnimal const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
