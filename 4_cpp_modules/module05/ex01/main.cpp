/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/04 11:42:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"

int main()
{
	Bureaucrat	bureaucrat;
	Bureaucrat 	b1("James", 4);
	Bureaucrat 	b2(b1);
	Form		test("Generic form", 150, 112);
	Form		serious("War declaration", 1, 1);
	Form		generic;
	Form		copying(serious);

	try
	{
		std::cerr << GR << "Trying to execute beSigned function with an unauthorized bureaucrat" << std::endl << BLANK;
		serious.beSigned(b2);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << std::endl << BLANK;
	}
	b1.signForm(test);
	std::cerr << GR << "signForm has an implemented catch try block, no exceptions in the main function" << std::endl << BLANK;
	b1.signForm(copying);
	std::cout << test << std::endl;
	std::cout << serious << std::endl;
	try
	{
		std::cerr << GR << "Trying to increase the grade over the cap" << std::endl << BLANK;
		b1.increaseGrade(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl << BLANK;
	}
	return (0);
}
