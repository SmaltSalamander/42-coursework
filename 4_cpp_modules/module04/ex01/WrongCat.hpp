/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/31 09:44:15 by sbienias         ###   ########.fr       */
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