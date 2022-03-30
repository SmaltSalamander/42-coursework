/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 16:33:41 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
// #include "ClapTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{

private:
    std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
    DiamondTrap(const DiamondTrap &ptr);
    DiamondTrap &operator=(DiamondTrap const &right);
    void attack(const std::string& target);
    void  whoAmI();
};

#endif