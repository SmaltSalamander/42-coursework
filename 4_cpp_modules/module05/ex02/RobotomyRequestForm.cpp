/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors/Destructors/Operators

RobotomyRequestForm::RobotomyRequestForm(void) : Form(" ", "RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
Form(target, "RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ptr) : Form::Form(ptr)
{
	std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
	*this = ptr;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &right)
{
	std::cout << "RobotomyRequestForm's overload assignment operator called" << std::endl;
	this->getTarget() = right.getTarget();
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
	std::cout << "WRRRRRRRYYYYYYY" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 100 < 50)
		std::cout << "SUCCESS! The Robotomy on " << this->getTarget() << "succeded!" << std::endl;
	else
		std::cout << "The Robotomy on " << this->getTarget() << "failed" << std::endl;
}

std::ostream &operator<<(std::ostream &outstrobj, RobotomyRequestForm const &right)
{
	outstrobj << "RobotomyRequestForm name: " << right.getName();
	outstrobj << ", status: ";
	if (right.isSigned() == true)
		outstrobj << "signed";
	else
		outstrobj << "unsigned";
	outstrobj << ", Grade needed to sign: " << right.getSignGrade() << ", to execute: " <<
	right.getExecGrade();
	return (outstrobj);
}
