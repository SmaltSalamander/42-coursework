/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/13 14:19:18 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <iostream>
#include <cstdlib>
#include <string>

# define BLANK "\e[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GR "\033[0;32m"
# define YE "\033[0;33m"
# define BL "\033[0;34m"
# define PU "\033[0;35m"
# define CY "\033[0;36m"
# define WH "\033[0;37m"
# define D "\033[0m"

class	ClapTrap
{

protected:
    std::string     _name;
    int             _hp;
    int             _energ;
    unsigned int    _attdmg;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
    ClapTrap(const ClapTrap &ptr);
    ClapTrap &operator=(ClapTrap const &right);
	std::string		getName();
	unsigned int	getDmg();
	int				getHp();
	int				getEng();
    void 			setAttDmg(unsigned int  amount);
    void virtual	attack(const std::string& target);
    void 			takeDamage(unsigned int amount);
    void 			beRepaired(unsigned int amount);
};

#endif