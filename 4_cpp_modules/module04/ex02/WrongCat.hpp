/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:09 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/06 15:06:12 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{

private:
public:
	WrongCat(void);
	// WrongCat(std::string name);
	~WrongCat(void);
    WrongCat(const WrongCat &ptr);
    WrongCat &operator=(WrongCat const &right);
    void    makeSound() const;
};

#endif