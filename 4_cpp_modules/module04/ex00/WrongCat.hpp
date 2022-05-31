/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/23 09:38:03 by sbienias         ###   ########.fr       */
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
public:
	WrongCat(void);
	~WrongCat(void);
    WrongCat(const WrongCat &ptr);
    WrongCat &operator=(WrongCat const &right);
    void    makeSound() const;
};

#endif