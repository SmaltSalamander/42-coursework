/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:05:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 19:20:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria Constructor called" << std::endl;
	this->type = "default";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria Constructor called" << std::endl;
	this->type = type;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &ptr)
{
	std::cout << "AMateria's copy constructor called" << std::endl;
	*this = ptr;
}

AMateria &AMateria::operator=(AMateria const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	if (this != &right)
		this->type = right.type;
	return (*this);
}

std::string const &  AMateria::getType() const
{
	return (type);
}

// std::ostream &operator<<(std::ostream &outstrobj, AMateria const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
