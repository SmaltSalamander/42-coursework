/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 17:48:46 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int	a = 3;
	int b = 13;

	std::cout << "Testing two numbers, " << a << " and " << b << std::endl;
	swap<int>(a, b);
	std::cout << "Now they're " << a << " and " << b << std::endl;
	std::cout << "The bigger one is " << max<int>(a, b) << " and the smaller is " << min<int>(a, b) << std::endl;
	float	test = 5.13;
	float	test2 = 3.14;
	std::cout << "Testing two floats, " << test << " and " << test2 << std::endl;
	swap<float>(test, test2);
	std::cout << "Now they're " << test << " and " << test2 << std::endl;
	a = 2;
	b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
}
