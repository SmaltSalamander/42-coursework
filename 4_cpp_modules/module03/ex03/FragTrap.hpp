/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 16:33:45 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{

private:

public:	
    FragTrap(void);
	FragTrap(std::string name);
	~FragTrap(void);
    FragTrap(const FragTrap &ptr);
    FragTrap &operator=(FragTrap const &right);
    void    setHitPoints();
    void    setAttackDamage();
    void    highFivesGuys();
};

#endif