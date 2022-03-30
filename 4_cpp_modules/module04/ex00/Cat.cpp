/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 18:12:11 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
}

Cat::Cat(std::string name)
{
	type = name;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &ptr)
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
	std::cout << this->type << "meows" << std::endl;	
}

// std::ostream &operator<<(std::ostream &outstrobj, Cat const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
