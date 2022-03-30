/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 16:45:12 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	// ClapTrap mobA("Wally");
	// ScavTrap mobB("Poe");
	// FragTrap mobD;
	DiamondTrap mobZ("Joe");
	// DiamondTrap mobL;
	
	mobZ.guardGate();
	mobZ.whoAmI();
		// mobL.whoAmI();

	// mobA.attack("A box");
	// mobB.guardGate();
	// FragTrap mobC("Mooley");
	return 0;
}