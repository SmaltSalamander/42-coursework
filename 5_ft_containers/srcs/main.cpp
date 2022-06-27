/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/24 14:21:22 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "vector.hpp"
#include "iterator_v.hpp"
#include <vector>

int main(void)
{
	std::vector<int>			wa(3);
	ft::vector<int>				wa2(3);

	wa.push_back(5);
	wa.push_back(5);

	wa2.push_back(5);
	wa2.push_back(5);
	wa2.push_back(5);
	wa2.push_back(5);
	std::vector<int>::iterator	test(wa.end());
	--test; 
	ft::vector<int>::iterator	test2(wa2.end());
	--test2;
	std::cout << *test << std::endl << *test2 << std::endl;
	return(0);
}
