/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/23 20:05:05 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
using std::string;
#include <cstdlib>

int	main(void)
{
	Zombie *zombies = NULL;

	zombies = zombieHorde(10, "Fella");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
