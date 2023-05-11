/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:53:16 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 01:46:09 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

/**
 Public class -> 
 Private class -> 
 */
class Contact
{
    public:
		Contact();
		~Contact();

		
		void add();
		void displayContact() const;
		void displayAll() const;
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string 	_phoneNumber;
		std::string 	_darkestSecret;

		std::string _addInfo(std::string text) const;
		std::string _formatInfo(std::string info) const;
};

#endif
