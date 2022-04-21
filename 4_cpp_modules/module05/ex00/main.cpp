/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:17:47 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat;
	Bureaucrat b1("James", 4);
	try
	{
		Bureaucrat cheater("ASDF", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	try
	{
		b1.increaseGrade(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	std::cout << b1 << std::endl;
	b1.decreaseGrade(146);
	std::cout << b1 << std::endl;
	try
	{
		b1.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	return (0);
}
