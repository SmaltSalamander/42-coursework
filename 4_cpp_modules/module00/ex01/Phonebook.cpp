/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:41:22 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 11:40:06 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->len = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::Add()
{
	int	index;

	if (this->len == 8)
	{
		index = 1;
		while (index < 8)
		{
			this->contacts[index - 1] = this->contacts[index];
			index++;
		}
		index--;
	}
	else
		index = this->len;
	this->contacts[index].SetVals();
	if (this->len != 8)
		this->len++;
	return ;
}

void	PhoneBook::Retrieve()
{
	int	index;
	std::string	newlinecatch;

	if (this->len == 0)
	{
		std::cout << "No contacts found in the phonebook, ADD some first" << std::endl;
		return ;
	}
	for (int i = 0; i < this->len; i++)
		this->contacts[i].DisplayRow(i);
	std::cout << "Choose index: ";
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index > this->len - 1)
	{
		std::cin.clear();
		std::cout << "Wrong index input" << std::endl;
	}
	else
		this->contacts[index].PrintOut();
	std::getline(std::cin, newlinecatch);
	return ;
}
