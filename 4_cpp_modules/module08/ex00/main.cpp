/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/06 13:35:27 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::list<int>	test;
	std::list<int>::iterator it;
	std::vector<int>	vect;
	std::vector<int>::iterator vec_i;

	for (int i = 1; i < 10; i++)
	{
		test.push_back(i);
		vect.push_back(i % 3 * 2);
	}
	it = ::easyfind(test, 8);
	std::cout << "Found here " << *it << std::endl;
	vec_i = ::easyfind(vect, 4);
	std::cout << "Found here " << *vec_i << std::endl;
	std::cout << "Members of list:" << std::endl;
	it = test.begin();
	for (int i = 1; i < 10; i++)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "Members of vector:" << std::endl;
	vec_i = vect.begin();
	for (int i = 1; i < 10; i++)
	{
		std::cout << *vec_i << std::endl;
		++vec_i;
	}
	try
	{
		vec_i = ::easyfind(vect, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
