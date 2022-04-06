/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 13:41:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "AMateria.hpp"

class	Ice : public AMateria
{

protected:
    const std::string &type;
public:
	Ice(void);
    Ice(std::string const & type);
	~Ice(void);
    Ice(const Ice &ptr);
    Ice &operator=(Ice const &right);
	Ice* clone();
	void use(ICharacter& target);
};

#endif