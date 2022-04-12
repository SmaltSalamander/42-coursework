/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 11:42:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Constructor called" << std::endl;
	type = "WrongCat";
}

// WrongCat::WrongCat(std::string name)
// {
// 	type = name;
// }

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ptr) : WrongAnimal::WrongAnimal(ptr)
{
	std::cout << "WrongCat's copy constructor called" << std::endl;
	*this = ptr;
}

WrongCat &WrongCat::operator=(WrongCat const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->type = right.type;
	return (*this);
}

void    WrongCat::makeSound() const
{
	std::cout << this->type << " meows" << std::endl;	
}

// std::ostream &operator<<(std::ostream &outstrobj, WrongCat const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
