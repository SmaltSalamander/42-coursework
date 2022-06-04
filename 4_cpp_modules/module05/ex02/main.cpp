/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/04 12:15:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "color.h"

int main()
{
	Bureaucrat	bureaucrat;
	Bureaucrat 	b1("James", 20);
	Bureaucrat 	b2(b1);
	Bureaucrat  b9000("Ba", 130);
	ShrubberyCreationForm		test("Krisi");
	Form						*test1 = new RobotomyRequestForm();
	PresidentialPardonForm		mistake("Joe");
	// If uncommented, can see compilation issue "abstract class"
	// Form form;
	std::cout << BL << test << std::endl << *test1 << std::endl << mistake << std::endl;
	test1->setTarget("Greymon");
	std::cout << PU;
	b1.signForm(*test1);
	test1->execute(b9000);
	test1->execute(b2);
	std::cout << GR;
	b9000.signForm(test);
	test.execute(b1);
	std::cout << CY;
	b1.signForm(mistake);
	std::cout << RED;
	b1.executeForm(mistake);
	//mistake.execute(b1);
	std::cout << BLANK << test << std::endl;
	delete test1;
	return (0);
}
