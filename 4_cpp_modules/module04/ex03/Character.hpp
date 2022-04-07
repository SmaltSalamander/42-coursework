/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 19:58:45 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
	AMateria	*_inv[4];
public:
    Character();
    ~Character();
    Character(const Character &ptr);
    Character &operator=(Character const &right);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif