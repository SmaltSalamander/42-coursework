/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 13:58:00 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Data.hpp"

int main(void)
{
	Data			data(123);
	Data			*blah = new Data(123);
	uintptr_t		middle_val;
	Data			*test;
	
	middle_val = serialize(&data);
	test = deserialize(middle_val);
	std::cout << test << " and " << &data << "; Address as unitptr: " << middle_val << std::endl;
	if (test == &data)
		std::cout << "Serialization completed succefully" << std::endl;
	std::cout << "Unrelated object: " << blah << std::endl;
	delete blah;
	return (0);
}
