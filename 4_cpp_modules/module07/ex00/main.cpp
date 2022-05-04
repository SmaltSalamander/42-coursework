/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 16:42:20 by sbienias         ###   ########.fr       */
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
	return (0);
}
