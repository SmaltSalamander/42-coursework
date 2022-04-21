/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:15:50 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <cstdlib>
#include <string>

# define BLANK "\e[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GR "\033[0;32m"
# define YE "\033[0;33m"
# define BL "\033[0;34m"
# define PU "\033[0;35m"
# define CY "\033[0;36m"
# define WH "\033[0;37m"
# define D "\033[0m"

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