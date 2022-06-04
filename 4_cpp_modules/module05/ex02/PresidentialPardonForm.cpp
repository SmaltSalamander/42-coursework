/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:09:41 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/04 12:04:31 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors/Destructors/Operators

PresidentialPardonForm::PresidentialPardonForm(void) : Form(" ", "PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
Form(target, "PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ptr) : Form::Form(ptr)
{
	std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
	*this = ptr;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &right)
{
	std::cout << "PresidentialPardonForm's overload assignment operator called" << std::endl;
	this->getTarget() = right.getTarget();
	return (*this);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &outstrobj, PresidentialPardonForm const &right)
{
	outstrobj << "PresidentialPardonForm name: " << right.getName();
	outstrobj << ", status: ";
	if (right.isSigned() == true)
		outstrobj << "signed";
	else
		outstrobj << "unsigned";
	outstrobj << ", Grade needed to sign: " << right.getSignGrade() << ", to execute: " <<
	right.getExecGrade();
	return (outstrobj);
}
