/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 11:43:34 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

// Dog::Dog(std::string name)
// {
// 	type = name;
// }

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &ptr) : Animal::Animal(ptr), Brain::Brain(ptr)
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

// std::ostream &operator<<(std::ostream &outstrobj, Dog const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
