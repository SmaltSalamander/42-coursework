/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp              		                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors/Destructors/Operators

MutantStack::MutantStack(void) : _size(0)
{
	std::cout << "MutantStack Constructor called" << std::endl;
}

MutantStack::MutantStack(unsigned int storage) : _size(storage)
{
	std::cout << "MutantStack Constructor called" << std::endl;
}

MutantStack::~MutantStack(void)
{
	std::cout << "MutantStack Destructor called" << std::endl;
}

MutantStack::MutantStack(const MutantStack &ptr) : _MutantStack(ptr._MutantStack), _size(ptr._size)
{
	std::cout << "MutantStack's copy constructor called" << std::endl;
}

MutantStack &MutantStack::operator=(MutantStack const &right)
{
	std::cout << "MutantStack's overload assignment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &outstrobj, MutantStack const &right)
{
	outstrobj << "MutantStack capacity: ";
	return (outstrobj);
}
