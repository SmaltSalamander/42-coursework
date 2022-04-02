/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/02 12:08:25 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class	Brain
{

protected:
    std::string *ideas;
public:
    Brain(void);
	~Brain(void);
    Brain(const Brain &ptr);
    Brain &operator=(Brain const &right);
    void    setIdea(int index, std::string idea);
    std::string getIdea(int index);

};

#endif