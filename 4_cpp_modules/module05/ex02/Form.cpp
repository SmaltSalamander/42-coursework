/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors/Destructors/Operators

Form::Form(void) : _name(" "), _signed(false), _reqGradeSign(150), _reqGradeExec(150), _target("")
{
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(std::string target, const std::string name, int gradeSign, int gradeExec) : _name(name),
_signed(false), _reqGradeSign(gradeSign), _reqGradeExec(gradeExec), _target(target)
{
	std::cout << "Form Constructor called" << std::endl;
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooHighException());
	else if (gradeSign < 0 || gradeExec < 0)
		throw (Form::GradeTooLowException());
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &ptr) : _name(ptr._name), _reqGradeSign(ptr._reqGradeSign),
_reqGradeExec(ptr._reqGradeExec)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &right)
{
	std::cout << "Form's overload assignment operator called" << std::endl;
	this->_signed = right._signed;
	this->_target = right._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, Form const &right)
{
	outstrobj << "Form name: " << right.getName();
	outstrobj << ", status: ";
	if (right.isSigned() == true)
		outstrobj << "signed";
	else
		outstrobj << "unsigned";
	outstrobj << ", Grade needed to sign: " << right.getSignGrade() << ", to execute: " <<
	right.getExecGrade();
	return (outstrobj);
}

// Exceptions

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("The form was not signed!");
}

// Methods

const std::string 	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getSignGrade(void) const
{
	return (this->_reqGradeSign);
}

int			Form::getExecGrade(void) const
{
	return (this->_reqGradeExec);
}

std::string			Form::getTarget(void) const
{
	return (this->_target);
}

bool		Form::isSigned(void) const
{
	return (this->_signed);
}

void		Form::beSigned(Bureaucrat &p)
{
	if (p.getGrade() <= this->_reqGradeSign)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
}

void		Form::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw (Form::FormNotSignedException());
	else if (executor.getGrade() > this->_reqGradeExec)
		throw (Form::GradeTooLowException());
}