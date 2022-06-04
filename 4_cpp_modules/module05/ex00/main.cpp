/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 09:46:14 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.h"

int main()
{
	Bureaucrat bureaucrat;
	Bureaucrat b1("James", 4);
	Bureaucrat b2(b1);
	try
	{
		std::cerr << GR << "Trying to initialize a buraucrat with too high of a grade" << std::endl << BLANK;
		Bureaucrat cheater("ASDF", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	try
	{
		std::cerr << GR << "Trying to increase the grade over the cap" << std::endl << BLANK;
		b1.increaseGrade(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	std::cout << b1 << std::endl;
	std::cerr << GR << "Demoting by 146" << std::endl << BLANK;
	b1.decreaseGrade(146);
	std::cout << b1 << std::endl << b2 << std::endl;
	try
	{
		std::cerr << GR << "Trying to decrease the grade over the cap" << std::endl << BLANK;
		b1.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << BLANK;
	}
	return (0);
}
