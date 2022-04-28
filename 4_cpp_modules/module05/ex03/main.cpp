/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/28 21:14:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern a;
	Intern b;
	Form	*test;
	Form	*another;

	b = a;
	test = a.makeForm("shrubbery request", "home");
	std::cout << *test << std::endl;
	another = a.makeForm("presidential pardon", "Joe");
	delete test;
	delete another;
	try
	{
		another = a.makeForm("shrubbery robotomy", "Plant enthusiast");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
