/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/23 09:37:54 by sbienias         ###   ########.fr       */
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
	~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &ptr);
    WrongAnimal &operator=(WrongAnimal const &right);
    std::string     getType() const;
    void    makeSound() const;
};

#endif