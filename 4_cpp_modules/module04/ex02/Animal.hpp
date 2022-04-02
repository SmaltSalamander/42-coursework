/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/02 14:51:03 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class	Animal
{

protected:
    std::string type;
public:
    Animal(void);
	virtual ~Animal(void);
    Animal(const Animal &ptr);
    Animal &operator=(Animal const &right);
    std::string     getType() const;
    virtual void    makeSound() const = 0;
};

#endif