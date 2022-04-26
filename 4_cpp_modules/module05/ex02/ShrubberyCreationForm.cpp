/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors/Destructors/Operators

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("", "ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
Form(target, "ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ptr) : Form::Form(ptr)
{
	std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
	*this = ptr;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &right)
{
	std::cout << "ShrubberyCreationForm's overload assignment operator called" << std::endl;
	this->getTarget() = right.getTarget();
	return (*this);
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		Form::execute(executor);
	}
	catch (const std::exception& e)
	{
		std::cout << "Executor " << executor.getName() << " wasn't qualified: " << e.what() << std::endl;
		return ;
	}
	
}

std::ostream &operator<<(std::ostream &outstrobj, ShrubberyCreationForm const &right)
{
	outstrobj << "ShrubberyCreationForm name: " << right.getName();
	outstrobj << ", status: ";
	if (right.isSigned() == true)
		outstrobj << "signed";
	else
		outstrobj << "unsigned";
	outstrobj << ", Grade needed to sign: " << right.getSignGrade() << ", to execute: " <<
	right.getExecGrade();
	return (outstrobj);
}
