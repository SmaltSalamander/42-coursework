/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/30 10:25:54 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
private:
    Brain   *_brain;
public:
	Dog(void);
	~Dog(void);
    Dog(const Dog &ptr);
    Dog &operator=(Dog const &right);
    void    makeSound() const;
    void    makeIdea(int index, std::string idea);
    std::string seeIdea(int index);
};

#endif