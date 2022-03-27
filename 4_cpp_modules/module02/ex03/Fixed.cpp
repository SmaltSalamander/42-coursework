/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 14:15:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixednum = 0;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixednum = num << _fracBitsNum;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixednum = roundf(num  * (1 << _fracBitsNum));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ptr)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

Fixed &Fixed::operator=(Fixed const &right)
{
	// std::cout << "Overload assignment operator called" << std::endl;
	this->_fixednum = right.getRawBits();
	return (*this);
}

//Arithmetic operators
Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result(*this);
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result(*this);
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result(*this);
	result.setRawBits(this->getRawBits() * rhs.getRawBits() / (1 << _fracBitsNum));
	return (result);
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result(*this);
	if (rhs.getRawBits() != 0)
		result.setRawBits(this->getRawBits() * (1 << _fracBitsNum) / (rhs.getRawBits()));
	else
		std::cout << "Can't divide by zero, error" << std::endl;
	return (result);
}
//

//Comparison operators
bool  Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool  Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool  Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool  Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool  Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool  Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}
//

Fixed &Fixed::operator++(void)
{
	this->_fixednum += 1;
	return(*this);	
}

Fixed &Fixed::operator--(void)
{
	this->_fixednum -= 1;
	return(*this);	
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

int Fixed::getRawBits( void ) const
{
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

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 <= num2)
		return (num1);
	else
		return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}


std::ostream &operator<<(std::ostream &outstrobj, Fixed const &right)
{
	outstrobj << right.toFloat();
	return (outstrobj);
}

