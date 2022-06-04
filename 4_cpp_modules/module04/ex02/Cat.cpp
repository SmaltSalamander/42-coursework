/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/30 15:54:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &ptr) : Animal::Animal(ptr)
{
	std::cout << "Cat's copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = ptr;
}

Cat &Cat::operator=(Cat const &right)
{
	std::cout << "Cat Overload assignment operator called" << std::endl;
	*this->_brain = *right._brain;
	this->type = right.type;
	return (*this);
}

void    Cat::makeSound() const
{
	std::cout << this->type << " meows" << std::endl;	
}

void    Cat::makeIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::seeIdea(int index)
{
	return (this->_brain->getIdea(index));
}
