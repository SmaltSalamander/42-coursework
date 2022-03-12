/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:41:22 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/12 21:22:57 by sbienias         ###   ########.fr       */
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
	if (this->len == 7)
		index = 0;
	else
		index = this->len;
	this->contacts[index].SetVals();
	this->len++;
	return ;
}

void	PhoneBook::Retrieve()
{
	int	index;
	std::cin >> index;
	for (int i = 0; i < this->len; i++)
		this->contacts[i].DisplayRow(i);
	if (index < 0 || index > this->len)
		std::cout << "Wrong index input";
	return ;
}
