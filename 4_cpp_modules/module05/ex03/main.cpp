/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 17:37:19 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "color.h"

int main()
{
	Intern a;
	Intern b;
	Bureaucrat	joe("Joe", 1);
	Form	*test;
	Form	*another;

	b = a;
	std::cout << GR;
	test = a.makeForm("shrubbery request", "home");
	std::cout << YE << *test << std::endl << GR;
	another = a.makeForm("presidential pardon", "Joe");
	std::cout << CY;
	joe.signForm(*another);
	std::cout << BLANK;
	*test = *another;
	delete test;
	delete another;
	try
	{
		std::cout << GR << "Trying to make a form with invalid name (reference to two)" << std::endl;
		another = a.makeForm("shrubbery robotomy", "Plant enthusiast");
	}
	catch (const Intern::FormNameWrong& e)
	{
		std::cout << RED << e.what() << std::endl;
	}
	try
	{
		std::cout << GR << "Trying to make a form with invalid name (wrong name)" << std::endl;
		another = b.makeForm("parking slot allocation", "A driver");
	}
	catch (const Intern::FormNameWrong& e)
	{
		std::cout << RED << e.what() << std::endl << BLANK;
	}
	return (0);
}
