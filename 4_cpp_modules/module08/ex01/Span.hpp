/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/09 12:32:44 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <vector>
#include <algorithm> // min/max_element

class	Span
{
private:
	std::vector<int>		_span;
    unsigned int 			_size;
public:
	Span(void);
	Span(unsigned int storage);
	~Span(void);
    Span(const Span &ptr);
    Span &operator=(Span const &right);
	unsigned int 	getSize(void) const;
	void			addNumber(int	value);
	void			addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	void			fillRandom(void);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	std::vector<int>::iterator	begin();
	std::vector<int>::iterator	end();
	class OutOfSpaceException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class NotEnough : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outstrobj, Span const &right);
int					randomVal(void);

#endif