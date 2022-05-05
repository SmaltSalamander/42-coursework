/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/05 12:59:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdint.h>

template<typename T>
class	Array
{
private:
	T * _content;
	unsigned int	_size;
public:
//	Constructors
	Array<T>(void)
	{
		std::cout << "Array's defualt constructor called" << std::endl;
		this->_size = 0;
		this->_content = NULL;
	}
    Array<T>(unsigned int n)
	{
		std::cout << "Array's value constructor called" << std::endl;
		this->_content = new T[n];
		this->_size = n;
    	// etc...
    }
    Array<T>(Array<T> const & list)
	{
		std::cout << "Array's copy constructor called" << std::endl;
		unsigned int i = -1;
		unsigned int	size = list.size();
		this->_content = new T[size];
		while (++i < size)
			this->_content[i] = list._content[i];
		this->_size = size;
    }
//	Destructor
    ~Array<T>(void)
	{
		std::cout << "Array's destructor called" << std::endl;
		if (this->_content)
        	delete[] this->_content;
    }
//	Overload
	Array &operator=(Array const &right)
	{
		std::cout << "Array's overload assignment operator called" << std::endl;
		this->_content = right._content;
		this->_size = right._size;
		return (*this);
	}
	T &operator[](unsigned int n)
	{
		if (this->_size <= n)
			throw std::exception();
		return (this->_content[n]);
	}
	T const &operator[](unsigned int n) const
	{
		if (this->_size <= n)
			throw std::exception();
		return (this->_content[n]);
	}
//	Getters
	unsigned int	size() const
	{
		return (this->_size);
	}
};

#endif