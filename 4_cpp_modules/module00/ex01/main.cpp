/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/12 21:26:22 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
using std::string;
#include <cstdlib>

int	main(void)
{
	// Contact 	temp;
	PhoneBook 	phonebook;
	string		str;

	std::cout << "Welcome to the PhoneBook, please enter EXIT, ADD or SEARCH to proceed" << std::endl;
	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, str))
			std::exit(1);
		else if (str == "EXIT")
			std::exit(0);
		else if (str == "ADD")
			phonebook.Add();
		else if (str == "SEARCH")
			phonebook.Retrieve();
		else
			std::cout << "Wrong input" << std::endl;
		str.clear();
		std::cin.clear();
	}
	// temp.SetVals();
	// temp.PrintOut();
	return (0);
	// while (1)
	// {
	// 	std::io
	// }
}
