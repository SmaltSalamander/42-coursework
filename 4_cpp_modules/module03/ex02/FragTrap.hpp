/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 19:49:06 by sbienias         ###   ########.fr       */
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
	FragTrap(std::string name);
	~FragTrap(void);
    FragTrap(const FragTrap &ptr);
    FragTrap &operator=(FragTrap const &right);
    void    highFivesGuys();
};

#endif