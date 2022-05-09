/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors/Destructors/Operators

Span::Span(void) : _size(0)
{
	std::cout << "Span Constructor called" << std::endl;
}

Span::Span(unsigned int storage) : _size(storage)
{
	std::cout << "Span Constructor called" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span Destructor called" << std::endl;
}

Span::Span(const Span &ptr) : _span(ptr._span), _size(ptr._size)
{
	std::cout << "Span's copy constructor called" << std::endl;
}

Span &Span::operator=(Span const &right)
{
	std::cout << "Span's overload assignment operator called" << std::endl;
	this->_size = right._size;
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, Span const &right)
{
	outstrobj << "Span capacity: " << right.getSize();
	std::vector<int>::iterator	start = const_cast<Span &>(right).begin();
	std::vector<int>::iterator	end = const_cast<Span &>(right).end();
	while (start != end)
	{
		std::cout << std::endl << *start;
		++start;
	}
	return (outstrobj);
}

unsigned int 	Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>::iterator	Span::begin()
{
	return (this->_span.begin());
}

std::vector<int>::iterator	Span::end()
{
	return (this->_span.end());
}


void			Span::addNumber(int	value)
{
	if (this->_span.size() == this->_size)
		throw (Span::OutOfSpaceException());
	_span.push_back(value);
}

void			Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start != end && this->_span.size() < this->_size)
	{
		addNumber(*start);
		++start;
	}
}

void			Span::fillRandom(void)
{
	int	counter = this->_span.size();
	int	capacity = this->_size;
	while (counter < capacity)
	{
		addNumber(randomVal());
		++counter;
	}
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>::iterator 	iter;
	std::vector<int>			cpy = this->_span;
	unsigned int			spanSize = -1;

	if (this->_span.size() < 2)
		throw (Span::NotEnough());
	std::sort(cpy.begin(), cpy.end());
	iter = cpy.begin();
	while (true)
	{
		if (iter == cpy.end() || spanSize == 0)
			break;
		if (abs(*iter - iter[1]) < spanSize)
			spanSize = abs(*iter - iter[1]);
		++iter;
	}
	return (spanSize);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>::iterator 	min;
	std::vector<int>::iterator 	max;

	if (this->_span.size() < 2)
		throw (Span::NotEnough());
	min = std::min_element(this->_span.begin(), this->_span.end());
	max = std::max_element(this->_span.begin(), this->_span.end());
	return (abs(*max - *min));
}

int					randomVal(void)
{
	int	result;

	result = std::rand() % 10000;
	return (result);
}

const char *Span::OutOfSpaceException::what(void) const throw()
{
	return ("The capacity of this container has been reached");
}

const char *Span::NotEnough::what(void) const throw()
{
	return ("There's not enough elements within the container to find a span");
}
