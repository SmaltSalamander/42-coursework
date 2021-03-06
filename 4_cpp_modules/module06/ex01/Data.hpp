/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 13:58:43 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdint.h>

class	Data
{
private:
    unsigned int 		_value;
public:
    Data(void);
	Data(unsigned int 		value);
	~Data(void);
    Data(const Data &ptr);
    Data &operator=(Data const &right);
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif