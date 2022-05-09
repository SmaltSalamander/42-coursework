/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/09 15:08:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "Span.hpp"

int main(void)
{
	Span	span(10);
	Span	span2(11000);
	Span	span3(5);
	std::srand(std::time(0));
	for (int i = 0; i < 9; i++)
		span.addNumber(i);
	span.addNumber(3);
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << span << std::endl;

	//span2.addNumber(span2.begin(), span2.end());
	span2.fillRandom();
	//std::cout << span2 << std::endl;
	std::cout << "Shortest span of span2(11000 elements): " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span of span2(11000 elements): " << span2.longestSpan() << std::endl;
	try
	{
		span3.addNumber(span2.begin(), span2.end());
	}
	catch(const Span::OutOfSpaceException& e)
	{
		std::cerr << "Ran out of space!" << '\n';
	}
	std::cout << span3 << std::endl;
	std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span3.longestSpan() << std::endl;
}
