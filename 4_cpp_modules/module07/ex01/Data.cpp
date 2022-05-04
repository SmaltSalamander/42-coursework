/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructors/Destructors/Operators

Data::Data(void) : _value(42)
{
	std::cout << "Data Constructor called" << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data Destructor called" << std::endl;
}

Data::Data(const Data &ptr) : _value(ptr._value)
{
	std::cout << "Data's copy constructor called" << std::endl;
}

unsigned int Data::getValue(void) const
{
	return (this->_value);
}

Data &Data::operator=(Data const &right)
{
	std::cout << "Data's overload assignment operator called" << std::endl;
	this->_value = right._value;
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, Data const &right)
{
	outstrobj << "Data value: " << right.getValue();
	return (outstrobj);
}