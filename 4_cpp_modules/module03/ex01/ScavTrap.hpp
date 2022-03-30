/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:22:06 by sbienias         ###   ########.fr       */
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
};

#endif