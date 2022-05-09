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
	MutantStack(void);
	MutantStack(unsigned int storage);
	~MutantStack(void);
    MutantStack(const MutantStack &ptr);
    MutantStack<T> &operator=(MutantStack const &right);

	std::stack<T>::iterator	begin()
	{
		return (std::stack<T>::begin());
	}
	std::stack<T>::iterator	end()
	{
		return (std::stack<T>::end());
	}
};

template <typename T>
std::ostream &operator<<(std::ostream &outstrobj, MutantStack<T> const &right);

#endif