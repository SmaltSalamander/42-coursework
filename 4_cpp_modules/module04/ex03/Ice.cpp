/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 19:32:24 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const & type)
{
	this->type = type;
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

Ice::Ice(const Ice &ptr)
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

// std::ostream &operator<<(std::ostream &outstrobj, Ice const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
