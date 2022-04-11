/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/11 12:16:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"
#include "Point.h"

int main( void )
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 2);
	Point	d(1, 7);
	bool result = bsp(a, b, c, d);
	std::cout << "Point far away: " << result << std::endl;
	result = bsp(a, b, c, Point (3, 1));
	std::cout << "Point inside: " << result << std::endl;
	return 0;
}
