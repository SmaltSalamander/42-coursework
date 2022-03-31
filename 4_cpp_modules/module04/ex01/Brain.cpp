/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:07 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 18:12:32 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &ptr)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	*this = ptr;
}

Brain &Brain::operator=(Brain const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	this->ideas = right.ideas;
	return (*this);
}
