/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/22 14:35:33 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors/Destructors/Operators

Intern::Intern(void) : _name(" ")
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &ptr) : _name(ptr._name)
{
	std::cout << "Intern's copy constructor called" << std::endl;
	*this = ptr;
}

Intern &Intern::operator=(Intern const &right)
{
	std::cout << "Intern's overload assignment operator called" << std::endl;
	this->_grade = right._grade;
	return (*this);
}

// Methods

Form	*Intern::makeForm(std::string formName, std::string target)
{
	Form	*res;
	int		i = 0;
	int		selected;
	std::string	keyWords = {"shrubbery", "robotomy", "pardon"};
	Form	

	for (int a = 0; a < 3; a++)
	{
		if (formName.find(keyWords[a]))
		{
			selected = a;
			i++;
		}
	}
	if (a == 3 || i > 1)
		throw (FormNameWrong());
	std::cout << "Intern creates " << res->getName();
	return (res);
}
