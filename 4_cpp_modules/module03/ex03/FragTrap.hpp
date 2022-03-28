/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 17:37:01 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
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