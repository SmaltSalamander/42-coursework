/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 13:55:39 by sbienias         ###   ########.fr       */
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
	std::ofstream	dest;
	string	filename;
	string	s1;
	string	s2;
	string	line;
	size_t	i;
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
	fd.open(filename.c_str());
	if (!fd.is_open())
		return (1);
	string replace = filename + ".replace";
	dest.open(replace.c_str());
	if (!fd.is_open())
		return (1);
	while (getline(fd, line))
	{
		i = line.find(s1);
		if (i != std::string::npos)
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
		}
		dest << line << std::endl;
	}
	return (0);
}