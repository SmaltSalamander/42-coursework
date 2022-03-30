/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 18:08:38 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
}

Animal::Animal(std::string name)
{
	type = name;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &ptr)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	*this = ptr;
}

Animal &Animal::operator=(Animal const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->type = right.type;
	return (*this);
}

void    Animal::makeSound() 
{
	std::cout << this->type << "whines";	
}

std::string     Animal::getType()
{
	return (type);
}

// std::ostream &operator<<(std::ostream &outstrobj, Animal const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }