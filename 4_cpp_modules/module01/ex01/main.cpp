/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 17:09:10 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	Zombie *zombies = NULL;
	int		N;

	while (1)
	{
		std::cout << "Enter the number of zombies: ";
		std::cin >> N;
		if (std::cin.fail() || N < 1)
		{
			std::cout << "Please enter a positive number" << std::endl;
			std::cin.clear();
		}
		else
			break ;
	}
	zombies = zombieHorde(N, "Joe");
	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete [] zombies;
	return (0);
}
