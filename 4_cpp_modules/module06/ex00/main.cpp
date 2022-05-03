/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/03 11:14:12 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <climits>
#include <limits>
#include <iomanip>

int	checkForPseudos(std::string str)
{
	double inf = std::numeric_limits<double>::infinity();
	float inff = std::numeric_limits<float>::infinity();

	if (!str.compare("-inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -" << inff << "f" << std::endl;
		std::cout << "double: -" << inff << std::endl;
	}
	else if (!str.compare("inff") || !str.compare("+inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << inff << "f" << std::endl;
		std::cout << "double: " << inff << std::endl;
	}
	else if (!str.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (!str.compare("-inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -" << inf << "f" << std::endl;
		std::cout << "double: -" << inf << std::endl;

	}
	else if (!str.compare("inf") || !str.compare("+inf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << inf << "f" << std::endl;
		std::cout << "double: " << inf << std::endl;
	}
	else if (!str.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	std::string				literal;
	unsigned char			c;
	long					intCheck;
	float					f;
	double					d;

	if (argc != 2)
		return (0);
	literal = (std::string)(char *) argv[1];
	int status = checkForPseudos(literal);
	if (status)
		return (0);
	if (literal.length() > 0)
	{
		if (literal.length() == 1 && !std::isdigit(literal.begin()[0]))
			std::cout << "char: " << literal << std::endl;
		else
		{
			c = (unsigned char)std::atoi((char *)argv[1]);
			if (std::isprint(c))
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		intCheck = std::atol((char *) argv[1]);
		if (intCheck < INT_MIN || intCheck > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << intCheck << std::endl;
		f = (float) std::atof((char *) argv[1]);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		d = std::atof((char *) argv[1]);
		std::cout << "double: " << d << std::endl;
	}
	return (0);
}
