/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 11:22:47 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
private:
    const std::string 		_name;
	bool					_signed;
	const int				_reqGradeSign;
	const int				_reqGradeExec;
	std::string				_target;
public:
    Form(void);
	Form(std::string target, const std::string name, int gradeSign, int gradeExec);
	virtual ~Form(void);
    Form(const Form &ptr);
    Form &operator=(Form const &right);
	const std::string	getName(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	std::string			getTarget(void) const;
	void				setTarget(std::string target);
	bool				isSigned(void) const;
	void				beSigned(Bureaucrat &p);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outstrobj, Form const &right);

#endif