/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 13:56:40 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const & atype)
{
	this->type = atype;
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &ptr) : AMateria::AMateria(ptr)
{
	std::cout << "Ice's copy constructor called" << std::endl;
	*this = ptr;
}

Ice &Ice::operator=(Ice const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	if (this != &right)
		this->type = right.getType();
	return (*this);
}

Ice* Ice::clone() const
{
	Ice *ret = new Ice(this->getType());
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// std::ostream &operator<<(std::ostream &outstrobj, Ice const &right)
// {
// 	outstrobj << right._type;
// 	return (outstrobj);
// }
