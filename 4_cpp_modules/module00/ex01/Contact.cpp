/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:00:11 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/12 21:23:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::SetVals()
{
	std::cout << "Enter contact:" << std::endl;
	std::cout << "First name: ";
	std::cin >> this->firstname;
	std::cout << "Last name: ";
	std::cin >> this->lastname;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Phone number: ";
	std::cin >> this->phonenum;
	std::cout << "Darkest secret: ";
	std::cin >> this->secret;
}

void Contact::PrintOut(void)
{
	std::cout << "First name: ";
	std::cout << this->firstname << std::endl;
	std::cout << "Last name: ";
	std::cout << this->lastname << std::endl;
	std::cout << "Nickname: ";
	std::cout << this->nickname << std::endl;
	std::cout << "Phone number: ";
	std::cout << this->phonenum << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << this->secret << std::endl;
	std::cin.clear();
}

void	Contact::DisplayRow(int index)
{
	std::cout << index << "|";
	std::cout << this->firstname << "|";
	std::cout << this->lastname << "|";
	std::cout << this->nickname << std::endl;
}
