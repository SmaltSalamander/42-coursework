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

Intern::Intern(void)
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &ptr)
{
	std::cout << "Intern's copy constructor called" << std::endl;
	*this = ptr;
}

Intern &Intern::operator=(Intern const &right)
{
	std::cout << "Intern's overload assignment operator called" << std::endl;
	(void)right;
	return (*this);
}

// Methods
Form	*Intern::makeShrubbery(std::string target)
{
	ShrubberyCreationForm	*res = new ShrubberyCreationForm(target);
	return (res);
}

Form	*Intern::makeRobotomy(std::string target)
{
	RobotomyRequestForm	*res = new RobotomyRequestForm(target);
	return (res);
}

Form	*Intern::makePardon(std::string target)
{
	PresidentialPardonForm	*res = new PresidentialPardonForm(target);
	return (res);
}

Form	*Intern::makeForm(std::string formName, std::string target)
{
	Form	*res;
	int		i = 0;
	int		a = 0;
	int		selected;
	std::string	keyWords[3] = {"shrubbery", "robotomy", "pardon"};
	Form	*(Intern::*Table[3])(std::string) =
	{
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePardon,
	};

	while (a < 3)
	{
		if (formName.find(keyWords[a]) != std::string::npos)
		{
			selected = a;
			i++;
		}
		a++;
	}
	if (i != 1)
		throw (FormNameWrong());
	res = (this->*Table[selected])(target);
	std::cout << "Intern creates " << res->getName() << std::endl;
	return (res);
}

const char *Intern::FormNameWrong::what(void) const throw()
{
	return ("The form matching the phrase has not been found!");
}
