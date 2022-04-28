/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/28 14:25:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	bureaucrat;
	Bureaucrat 	b1("James", 4);
	Bureaucrat 	b2(b1);
	Bureaucrat  b9000("Ba", 130);
	ShrubberyCreationForm		test("home");
	RobotomyRequestForm		test1;
	PresidentialPardonForm		mistake("Joe");
	test1.setTarget("Greymon");
	std::cout << PU;
	b1.signForm(test1);
	test1.execute(b9000);
	test1.execute(b2);
	std::cout << GR;
	b9000.signForm(test);
	test.execute(b1);
	std::cout << CY;
	b1.signForm(mistake);
	mistake.execute(b1);
	std::cout << BLANK << test << std::endl;
	return (0);
}
