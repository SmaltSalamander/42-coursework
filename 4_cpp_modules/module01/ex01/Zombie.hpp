/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:30 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 17:08:59 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>
#include <string>
class	Zombie
{

private:
	std::string _name;
public:
	Zombie(void);
	~Zombie(void);
	void	setName(std::string name);
	std::string	getName(void);
	void	announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif