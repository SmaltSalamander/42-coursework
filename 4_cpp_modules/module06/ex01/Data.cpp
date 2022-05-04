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

Data::Data(void)
{
	std::cout << "Data Constructor called" << std::endl;
}

Data::Data(unsigned int value) : _value(value)
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

Data &Data::operator=(Data const &right)
{
	std::cout << "Data's overload assignment operator called" << std::endl;
	this->_value = right._value;
	return (*this);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

