/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 17:52:55 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
}

Dog::Dog(std::string name)
{
	type = name;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &ptr)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	*this = ptr;
}

Dog &Dog::operator=(Dog const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->type = right.type;
	return (*this);
}

void    Dog::makeSound()
{
	std::cout << this->type << "barks";	
}

// std::ostream &operator<<(std::ostream &outstrobj, Dog const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
