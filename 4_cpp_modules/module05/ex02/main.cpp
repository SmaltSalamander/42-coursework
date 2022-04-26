/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/22 20:17:58 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat	bureaucrat;
	Bureaucrat 	b1("James", 4);
	Bureaucrat 	b2(b1);
	ShrubberyCreationForm		test;

	b1.signForm(test);
	test.execute(b1);
	std::cout << test << std::endl;
	try
	{
		b1.increaseGrade(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl << BLANK;
	}
	std::cout << b1 << std::endl;
	b1.decreaseGrade(146);
	std::cout << b1 << std::endl << b2 << std::endl;
	try
	{
		b1.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << std::endl << BLANK;
	}
	return (0);
}
