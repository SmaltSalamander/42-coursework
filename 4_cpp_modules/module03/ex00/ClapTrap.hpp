/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:20:07 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>

class	ClapTrap
{

protected:
    std::string     _name;
    int             _hp;
    int             _energ;
    unsigned int    _attdmg;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
    ClapTrap(const ClapTrap &ptr);
    ClapTrap &operator=(ClapTrap const &right);
    void setAttDmg(unsigned int  amount);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif