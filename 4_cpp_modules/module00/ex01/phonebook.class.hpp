/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:11:00 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/09 21:56:43 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <string.h>

class Contact
{
private:
	char	*firstname;
	char	*lastname;
	char	*nickname;
	char	*phonenum;
	char	*secret;
public:
	Contact CreateNewContact(void);
	Contact(/* args */);
	~Contact();
};

class	PhoneBook
{
	public:
		
		Contact contacts[8];
		PhoneBook(void); // CPP use the name of the class for constructor
		~PhoneBook(void); // and the name of the class for destructor
}; // don't forget to end with semicolon

#endif