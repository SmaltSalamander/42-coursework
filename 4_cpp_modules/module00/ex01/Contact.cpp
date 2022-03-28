/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:00:11 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 11:44:07 by sbienias         ###   ########.fr       */
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
	std::string	str;

	std::cout << "Enter contact:" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, str);
	setFirstname(str);
	std::cout << "Last name: ";
	std::getline(std::cin, str);
	setLastname(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	setNickname(str);
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	setPhonenum(str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	setSecret(str);
}

void Contact::PrintOut(void)
{
	std::cout << "First name: ";
	std::cout << getFirstname() << std::endl;
	std::cout << "Last name: ";
	std::cout << getLastname() << std::endl;
	std::cout << "Nickname: ";
	std::cout << getNickname() << std::endl;
	std::cout << "Phone number: ";
	std::cout << getPhonenum() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << getSecret() << std::endl;
	std::cin.clear();
}

void	Contact::DisplayRow(int index)
{
	std::cout << std::setw(10) << index + "|";
	if (getFirstname().length() < 11)
		std::cout << std::setw(10) << std::string(10 - getFirstname().length(), ' ') + getFirstname() + "|";
	else
		std::cout << std::setw(10) << getFirstname().substr(0, 9) + "." + "|";
	if (getLastname().length() < 11)
		std::cout << std::setw(10) << std::string(10 - getLastname().length(), ' ') + getLastname() + "|";
	else
		std::cout << std::setw(10) << getLastname().substr(0, 9) + "." + "|";
	if (getNickname().length() < 11)
		std::cout << std::setw(10) << std::string(10 - getNickname().length(), ' ') + getNickname();
	else
		std::cout << std::setw(10) << getNickname().substr(0, 9) + ".";
	std::cout << std::endl;
}

std::string Contact::getFirstname() const
{
	return (this->_firstname);
}
std::string Contact::getLastname() const
{
	return (this->_lastname);
}
std::string Contact::getNickname() const
{
	return (this->_nickname);
}
std::string Contact::getPhonenum() const
{
	return (this->_phonenum);
}
std::string Contact::getSecret() const
{
	return (this->_secret);
}

void	Contact::setFirstname(std::string str)
{
	this->_firstname = str;
}
void	Contact::setLastname(std::string str)
{
	this->_lastname = str;
}
void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
}
void	Contact::setPhonenum(std::string str)
{
	this->_phonenum = str;
}
void	Contact::setSecret(std::string str)
{
	this->_secret = str;
}
