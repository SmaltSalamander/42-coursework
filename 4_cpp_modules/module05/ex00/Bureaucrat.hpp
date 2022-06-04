/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/02 09:36:49 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class	Bureaucrat
{
private:
    const std::string 		_name;
	int					 	_grade;
public:
    Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat(void);
    Bureaucrat(const Bureaucrat &ptr);
    Bureaucrat &operator=(Bureaucrat const &right);
	const std::string getName(void) const;
	int	getGrade() const;
	void	increaseGrade(int amount);
	void	increaseGrade(void);
	void	decreaseGrade(int amount);
	void	decreaseGrade(void);
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outstrobj, Bureaucrat const &right);

#endif