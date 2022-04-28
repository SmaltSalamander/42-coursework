/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/27 13:47:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Form.hpp"
#include <fstream>

class	ShrubberyCreationForm : public Form
{
private:
public:
    ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &ptr);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &right);
	void		execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &outstrobj, ShrubberyCreationForm const &right);

#endif