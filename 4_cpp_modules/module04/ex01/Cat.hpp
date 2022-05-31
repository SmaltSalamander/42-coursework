/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/30 10:25:27 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
private:
    Brain   *_brain;
public:
	Cat(void);
	~Cat(void);
    Cat(const Cat &ptr);
    Cat &operator=(Cat const &right);
    void    makeSound() const;
    void    makeIdea(int index, std::string idea);
    std::string seeIdea(int index);
};

#endif