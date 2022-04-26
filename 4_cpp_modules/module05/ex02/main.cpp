/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/26 21:49:14 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat	bureaucrat;
	Bureaucrat 	b1("James", 4);
	Bureaucrat 	b2(b1);
	Bureaucrat  b9000("Ba", 130);
	ShrubberyCreationForm		test;
	RobotomyRequestForm		test1;

	b1.signForm(test);
	b1.signForm(test1);
	test1.execute(b9000);
	test.execute(b1);
	
	std::cout << test << std::endl;
	return (0);
}
