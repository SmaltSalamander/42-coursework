/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 18:06:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

class	Dog : public Animal
{

private:
    std::string _name;
public:
	Dog(void);
	Dog(std::string name);
	~Dog(void);
    Dog(const Dog &ptr);
    Dog &operator=(Dog const &right);
    void    makeSound() const;
};

#endif