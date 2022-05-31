/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/30 15:52:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &ptr) : Animal::Animal(ptr)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = ptr;
}

Dog &Dog::operator=(Dog const &right)
{
	std::cout << "Dog Overload assignment operator called" << std::endl;
	*this->_brain = *right._brain;
	this->type = right.type;
	return (*this);
}

void    Dog::makeSound() const
{
	std::cout << this->type << " barks" << std::endl;	
}

void    Dog::makeIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::seeIdea(int index)
{
	return (this->_brain->getIdea(index));
}

Brain	*Dog::getBrain()
{
	return (this->_brain);
}