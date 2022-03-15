/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:59:43 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/14 22:18:24 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void 		SetVals();
		void		PrintOut();
		void		DisplayRow(int);
		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getNickname() const;
		std::string getPhonenum() const;
		std::string getSecret() const;
		void		setFirstname(std::string);
		void		setLastname(std::string);
		void		setNickname(std::string);
		void		setPhonenum(std::string);
		void		setSecret(std::string);
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenum;
		std::string _secret;
};

#endif
