/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/24 21:40:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
using std::string;
#include <fstream>
using	std::fstream;

int main()
{
	fstream	fd;
	fstream	dest;
	string	filename;
	string	s1;
	string	s2;
	string	test;
	while (true)
	{
		std::cout << "Filename: ";
		std::cin >> filename;
		std::cout << "Search phrase: ";
		std::cin >> s1;
		std::cout << "Replace phrase: ";
		std::cin >> s2;
		if (!std::cin.fail())
			break ;
		else
		{
			std::cout << "Error encountered during data input, try again";
			std::cin.clear();
		}
	}
	fd.open(filename);
	if (!fd.is_open())
		return (1);
	dest.open(filename + ".replace");
	if (!fd.is_open())
		return (1);
	size_t	i;
	while (getline(fd, test))
	{
		i = test.find(s1);
		// std::cout << s1.length();
		if (i != std::string::npos)
		{
			
			std::cout << test.substr(i, s1.length());
		}
	}
	return (0);
}