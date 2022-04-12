/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 11:43:41 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

// Cat::Cat(std::string name)
// {
// 	type = name;
// }

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &ptr) : Animal::Animal(ptr), Brain::Brain(ptr)
{
	std::cout << "Cat's copy constructor called" << std::endl;
	*this = ptr;
}

Cat &Cat::operator=(Cat const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
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

// std::ostream &operator<<(std::ostream &outstrobj, Cat const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
