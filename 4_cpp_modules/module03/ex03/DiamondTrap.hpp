/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:49:36 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{

private:
    std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
    DiamondTrap(const DiamondTrap &ptr);
    DiamondTrap &operator=(DiamondTrap const &right);
    using ScavTrap::attack;
    void  whoAmI();
};

#endif