/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 11:41:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria	_inv[4];
public:
    Character();
    ~Character() {};
    std::string const & getName() const = 0;
    void equip(AMateria* m) = 0;
    void unequip(int idx) = 0;
    void use(int idx, ICharacter& target) = 0;
};

#endif