/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:24 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 15:06:26 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class	WrongAnimal
{

protected:
    std::string type;
public:
    WrongAnimal(void);
	// Animal(std::string name);
	~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &ptr);
    WrongAnimal &operator=(WrongAnimal const &right);
    std::string     getType() const;
    void    makeSound() const;
};

#endif