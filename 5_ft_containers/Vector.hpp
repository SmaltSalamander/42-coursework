/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:01:13 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/08 10:44:26 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Vector_HPP
# define Vector_HPP
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <ctime>
#include <algorithm> // min/max_element

namespace ft
{
template <typename T>
class	Vector
{
private:
	<T>				*_arr;
	allocator_type	_alloc;
	int				_len;
public:
	Vector(void)
	{
		arr = NULL;
		len = 0;
		std::cout << "Vector Constructor called" << std::endl;
	}
	~Vector()
	{
		if (arr)
			std::allocator<T>::deallocate(arr, len);
		std::cout << "Vector Destructor called" << std::endl;
	}
    Vector(const Vector<T> &ptr)
	{
		std::cout << "Vector's copy constructor called" << std::endl;
		*this = ptr;
	}
    Vector<T> &operator=(Vector<T> const &right)
	{
		std::cout << "Vector's overload assignment operator called" << std::endl;
		return (*this);
	}

typedef typename std::stack<T>::container_type::iterator iterator;
iterator	begin()
{
	return (std::stack<T>::c.begin());
}
iterator	end()
{
	return (std::stack<T>::c.end());
}
};
template <typename T>
std::ostream &operator<<(std::ostream &outstrobj, Vector<T> const &right)
{
	outstrobj << right.top();
	return (outstrobj);
}
}

#endif