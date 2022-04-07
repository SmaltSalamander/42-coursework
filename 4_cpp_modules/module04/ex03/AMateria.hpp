/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 19:32:50 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class   ICharacter;

class	AMateria
{
protected:
    std::string type;
public:
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(AMateria const &source);
	virtual ~AMateria(void);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    virtual AMateria &operator=(AMateria const &right);
};

#endif