/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:30 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/24 15:25:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
#include <iostream>
#include <string>
#include "Weapon.hpp"
using std::string;

class	HumanB
{

private:
	string _name;
	Weapon &_weapon;
public:
	HumanB(string name);
	~HumanB(void);
	void	setWeapon(Weapon &name);
	void	attack();
};

#endif