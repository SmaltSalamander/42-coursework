/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:30 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/15 15:29:38 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>
#include <string>
using std::string;

class	Zombie
{

private:
	string _name;
	Zombie* newZombie( std::string name );
public:
	Zombie(void);
	~Zombie(void);
	void	setName(string name);
	string	getName(void);
	void	announce(void);
	void randomChump( std::string name );
};

#endif