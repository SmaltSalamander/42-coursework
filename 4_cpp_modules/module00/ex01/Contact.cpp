/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:00:11 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/13 12:30:47 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

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
	std::string	newlinecatch;

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
	std::getline(std::cin, newlinecatch);
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
	std::cout << std::setw(10) << index << "|";
	if (this->firstname.length() < 11)
		std::cout << std::setw(10) << std::string(10 - this->firstname.length(), ' ') << this->firstname << "|";
	else
		std::cout << std::setw(10) << this->firstname.substr(0, 9) << "." << "|";
	if (this->lastname.length() < 11)
		std::cout << std::setw(10) << std::string(10 - this->firstname.length(), ' ') << this->lastname << "|";
	else
		std::cout << std::setw(10) << this->lastname.substr(0, 9) << "." << "|";
	if (this->nickname.length() < 11)
		std::cout << std::setw(10) << std::string(10 - this->firstname.length(), ' ') << this->nickname;
	else
		std::cout << std::setw(10) << this->nickname.substr(0, 9) << ".";
	std::cout << std::endl;
}
