/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/26 15:33:43 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixednum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixednum = num << _fracBitsNum;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixednum = roundf(num  * (1 << _fracBitsNum));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

Fixed &Fixed::operator=(Fixed const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_fixednum = right.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, Fixed const &right)
{
	outstrobj << right.toFloat();
	return (outstrobj);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixednum);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixednum = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float) _fixednum / (float)(1 << _fracBitsNum));
}

int Fixed::toInt( void ) const
{
	return (int)(this->toFloat());
}
