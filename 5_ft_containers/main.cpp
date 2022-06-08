/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/08 10:03:47 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

char	randomVal(void)
{
	char	result;

	result = std::rand() % (126 - 33) + 33;
	return (result);
}

int main(void)
{
	std::cout << "TESTING MUTANT STACK" << std::endl;
	ft::MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	ft::MutantStack<int>::iterator it = mstack.begin();
	ft::MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "MUTANT STACK END" << std::endl;

	std::cout << "TESTING LIST" << std::endl;
	std::list<int>	list_container;
	list_container.push_back(5);
	list_container.push_back(17);
	std::cout << list_container.back() << std::endl;
	list_container.pop_back();
	std::cout << list_container.size() << std::endl;
	list_container.push_back(3);
	list_container.push_back(5);
	list_container.push_back(737);
	list_container.push_back(0);
	std::list<int>::iterator lit = list_container.begin();
	std::list<int>::iterator lite = list_container.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::cout << "LIST END" << std::endl;
	std::srand(std::time(0));
	
	ft::MutantStack<char> str_stack;
	
	for (int i = 0; i < 10; i++)
		str_stack.push(randomVal());
	ft::MutantStack<char>::iterator cit = str_stack.begin();
	ft::MutantStack<char>::iterator cite = str_stack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	return(0);
}
