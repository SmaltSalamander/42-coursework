/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:05:56 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 12:46:33 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;

}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL)
			delete _memory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &ptr)
{
	std::cout << "MateriaSource's copy constructor called" << std::endl;
	*this = ptr;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &right)
{
	std::cout << "Overload assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i] != NULL)
			delete this->_memory[i];
		if (right._memory[i])
			this->_memory[i] = right._memory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *type)
{
	int	i = 0;

	while (i < 4 && _memory[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "The Materia was not learned" << std::endl;
		delete type;
		return ;
	}
	_memory[i] = type;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	AMateria	*result = NULL;

	while (i < 4 && _memory[i] && _memory[i]->getType() != type)
		i++;
	if (i == 4 || !_memory[i])
		std::cout << "No such materia as " << type << " found!" << std::endl;
	else
		result = _memory[i]->clone();
	return (result);
}

// std::ostream &operator<<(std::ostream &outstrobj, MateriaSource const &right)
// {
// 	outstrobj << right.type;
// 	return (outstrobj);
// }
