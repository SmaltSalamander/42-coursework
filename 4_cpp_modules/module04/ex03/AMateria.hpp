/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/02 15:36:35 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class	AMateria
{

protected:
    const std::string &type;
public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const & source);
	virtual ~AMateria(void);
    AMateria(const AMateria &ptr);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    virtual AMateria &operator=(AMateria const &right);
};

#endif