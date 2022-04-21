/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/20 23:12:23 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Cure::Cure(std::string const & atype)
// {
// 	this->type = atype;
// 	std::cout << "Cure Constructor called" << std::endl;
// }

Cure::Cure(void)
{
	this->type = "cure";
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &ptr) : AMateria::AMateria(ptr)
{
	std::cout << "Cure's copy constructor called" << std::endl;
	*this = ptr;
}

Cure &Cure::operator=(Cure const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	if (this != &right)
		this->type = right.getType();
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *ret = new Cure;
	return (ret);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

// std::ostream &operator<<(std::ostream &outstrobj, Cure const &right)
// {
// 	outstrobj << right._type;
// 	return (outstrobj);
// }
