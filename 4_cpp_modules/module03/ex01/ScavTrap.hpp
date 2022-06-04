/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 14:19:04 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{

private:

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
    ScavTrap(const ScavTrap &ptr);
    ScavTrap &operator=(ScavTrap const &right);
    void    guardGate();
	void 	attack(const std::string& target);
};

#endif