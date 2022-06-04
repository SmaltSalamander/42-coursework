/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 11:12:38 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class	Intern
{
public:
    Intern(void);
	~Intern(void);
    Intern(const Intern &ptr);
    Intern &operator=(Intern const &right);
	const std::string getName(void) const;
	Form	*makeForm(std::string formName, std::string target);
	Form	*makeShrubbery(std::string target);
	Form	*makeRobotomy(std::string target);
	Form	*makePardon(std::string target);
	class FormNameWrong : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif