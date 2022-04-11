/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/08 17:07:03 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed c = (float) 3.13;
	std::cout << c << std::endl;
	c = c / 2;
	std::cout << c << std::endl;
	c = c + 10 * 3 / 2;
	std::cout << c << std::endl;
	//subject's main
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	Fixed d = a;
	std::cout << d << std::endl;
	std::cout << a++ << std::endl;
	if (a != d)
		std::cout << "They're not equal (as it should be)!" << std::endl;
	std::cout << "a: " << a << "; d: " << d << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "The max value between a and b is " << Fixed::max( a, b ) << std::endl;
	std::cout << "The min value between a and b is " << Fixed::min( a, b ) << std::endl;
	return 0;
}