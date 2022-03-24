/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:15:18 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/23 20:23:53 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::string;
#include <cstdlib>

int main(void)
{
    string str = "HI THIS IS BRAIN";   
    string *stringPTR;
    string &stringREF = str;

    stringPTR = &str;
    std::cout << "Adress of string: " << &str << std::endl;
	std::cout << "Adress of PTR   : " << stringPTR << std::endl;
	std::cout << "Adress of REF   : " << &stringREF << std::endl;
	std::cout << "string          : " << str << std::endl;
	std::cout << "StringPTR       : " << *stringPTR << std::endl;
	std::cout << "StringREF       : " << stringREF << std::endl;
    return(0);
}
