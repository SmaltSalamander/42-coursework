/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 09:46:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors/Destructors/Operators

Bureaucrat::Bureaucrat(void) : _name(" ")
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());

}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ptr) : _name(ptr._name)
{
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
	*this = ptr;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->_grade = right._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, Bureaucrat const &right)
{
	outstrobj << right.getName() << ", bureaucrat grade " << right.getGrade();
	return (outstrobj);
}

// Exceptions

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

// Methods

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void	Bureaucrat::decreaseGrade(int amount)
{
	if (this->_grade + amount > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade += amount;
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::increaseGrade(int amount)
{
	if (this->_grade - amount < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade -= amount;
}
