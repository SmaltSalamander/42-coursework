/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/12 11:25:14 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "AMateria.hpp"

class	Cure : public AMateria
{

protected:
public:
	Cure(void);
    Cure(std::string const & type);
	~Cure(void);
    Cure(const Cure &ptr);
    Cure &operator=(Cure const &right);
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif