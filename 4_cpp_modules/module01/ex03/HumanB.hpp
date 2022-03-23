/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:30 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/23 20:52:31 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>
#include <string>
#include "Weapon.hpp"
using std::string;

class	HumanB
{

private:
	string _name;
	Weapon::Weapon _weapon;
public:
	HumanB(string name);
	~HumanB(void);
	void	setWeapon(Weapon name);
	void	attack();
};

#endif