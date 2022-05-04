/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 12:48:19 by sbienias         ###   ########.fr       */
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
    uintptr_t 		_value;
public:
    Data(void);
	Data(uintptr_t 		value);
	~Data(void);
    Data(const Data &ptr);
    Data &operator=(Data const &right);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif