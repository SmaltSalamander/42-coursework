/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/09 12:32:44 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <stack>
#include <algorithm> // min/max_element

template <typename T>
class	MutantStack : public std::stack<T>
{
public:
	MutantStack(void)
	{
		std::cout << "MutantStack Constructor called" << std::endl;
	}
	//MutantStack(unsigned int storage);
	~MutantStack()
	{
		std::cout << "MutantStack Destructor called" << std::endl;
	}
    MutantStack(const MutantStack<T> &ptr)
	{
		std::cout << "MutantStack's copy constructor called" << std::endl;
		*this = ptr;
	}
    MutantStack<T> &operator=(MutantStack<T> const &right)
	{
		std::cout << "MutantStack's overload assignment operator called" << std::endl;
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
std::ostream &operator<<(std::ostream &outstrobj, MutantStack<T> const &right)
{
	outstrobj << right.top();
	return (outstrobj);
}

#endif