/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:30 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/23 21:28:06 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
#include <iostream>
#include <string>
#include "Weapon.hpp"
using std::string;

class	HumanA
{

private:
	string _name;
	Weapon &_weapon;
public:
	HumanA(string name, Weapon &weapon);
	~HumanA(void);
	void	setWeapon(Weapon &name);
	void	attack();
};

#endif