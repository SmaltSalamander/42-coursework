/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 19:58:42 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixednum = 0;
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
	std::cout << "Copy assignment operator called" << std::endl;
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
