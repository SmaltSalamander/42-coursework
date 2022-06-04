/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 14:25:55 by sbienias         ###   ########.fr       */
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
	DiamondTrap mobA("FinalBoss");
	FragTrap compA("Wally");
	std::string	str;
	int			option;

	std::cout << RED;
	mobA.whoAmI();
	std::cout << "stands in your way!" << std::endl;
	mobA.highFivesGuys();
	std::cout << BLANK << "Go " << compA.getName() << "!" << std::endl;
	while (true)
	{
		std::cout << GR << "Choose action: " << std::endl;
		std::cout << "1. [ATTACK]    2. [HEAL]" << std::endl;
		std::cout << "3. [RUN AWAY]  4. [UPGRADE]" << std::endl << BLANK;
		std::cout << "[CHOOSE INDEX]: ";
		std::getline(std::cin, str);
		option = atoi(str.c_str());
		if (!std::cin.fail() && option > 0 && option < 5)
		{
			if (option == 3)
			{
				std::cout << "You and " << compA.getName() << " ran away safely!" << std::endl;
				return (0);
			}
			else if (option == 2)
				compA.beRepaired(5);
			else if (option == 1)
			{
				option = compA.getEng();
				compA.attack(mobA.getName());
				if (compA.getEng() < option)
					mobA.takeDamage(compA.getDmg());
			}
			else if (option == 4)
			{
				std::cout << "You modify " << compA.getName() << " and now it deals 1 more damage!" << std::endl;
				compA.setAttDmg(compA.getDmg() + 1);
			}
			if (mobA.getHp() <= 0)
			{
				std::cout << GR << "You defeated " << mobA.getName() << "! Congrats!" << BLANK << std::endl;
				return (0);
			}
		}
		else
		{
			std::cout << "Due to your confusion, " << mobA.getName() << " scores a hit!" << std::endl;
			mobA.attack(compA.getName());
			compA.takeDamage(mobA.getDmg());
			if (compA.getHp() <= 0)
			{
				std::cout << RED << "YOU DIED" << std::endl << WH;
				return (0);
			}
			mobA.guardGate();
			option = 0;
			std::cin.clear();
		}
	}
	return 0;
}
