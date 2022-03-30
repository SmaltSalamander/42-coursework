/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/30 18:06:25 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

class	Cat : public Animal
{

private:
    std::string _name;
public:
	Cat(void);
	Cat(std::string name);
	~Cat(void);
    Cat(const Cat &ptr);
    Cat &operator=(Cat const &right);
    void    makeSound() const;
};

#endif