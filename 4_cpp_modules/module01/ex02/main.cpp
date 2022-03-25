/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:15:18 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 17:08:26 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";   
    std::string *stringPTR;
    std::string &stringREF = str;

    stringPTR = &str;
    std::cout << "Adress of string: " << &str << std::endl;
	std::cout << "Adress of PTR   : " << stringPTR << std::endl;
	std::cout << "Adress of REF   : " << &stringREF << std::endl;
	std::cout << "string          : " << str << std::endl;
	std::cout << "StringPTR       : " << *stringPTR << std::endl;
	std::cout << "StringREF       : " << stringREF << std::endl;
    return(0);
}
