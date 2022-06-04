/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/22 15:29:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &ptr);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &right);
	void		execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstrobj, PresidentialPardonForm const &right);

#endif