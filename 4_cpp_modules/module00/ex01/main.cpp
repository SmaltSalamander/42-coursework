/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 10:27:02 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

int	main(void)
{
	PhoneBook 	phonebook;
	std::string		str;

	std::cout << "Welcome to the PhoneBook, please enter ADD, SEARCH or EXIT to proceed" << std::endl;
	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, str))
			std::exit(1);
		else if (str == "ADD")
			phonebook.Add();
		else if (str == "SEARCH")
			phonebook.Retrieve();
		else if (str == "EXIT")
			std::exit(0);
		else
			std::cout << "Wrong input; Type ADD, SEARCH or EXIT" << std::endl;
		str.clear();
		std::cin.clear();
	}
	return (0);
}
