/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/22 15:29:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
private:
public:
    RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &ptr);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &right);
	void		execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstrobj, RobotomyRequestForm const &right);

#endif