/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/23 09:38:11 by sbienias         ###   ########.fr       */
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
public:
	Dog(void);
	~Dog(void);
    Dog(const Dog &ptr);
    Dog &operator=(Dog const &right);
    void    makeSound() const;
};

#endif