/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/20 23:01:52 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_memory[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &ptr);
    MateriaSource &operator=(MateriaSource const &right);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif