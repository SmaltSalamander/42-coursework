/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:59:43 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/12 21:20:01 by sbienias         ###   ########.fr       */
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
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenum;
		std::string secret;
		void 	SetVals();
		void	PrintOut();
		void	DisplayRow(int);
};

#endif
