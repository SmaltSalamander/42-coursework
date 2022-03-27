/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 16:41:04 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 2);
	Point	d(2, 1.001);
	bool result = bsp(a, b, c, d);
	std::cout << result << std::endl;
	return 0;
}