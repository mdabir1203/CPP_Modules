/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:53:16 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/25 02:06:51 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

/**
 Public class -> 
 Private class -> 
 */
class Contact
{
    public:
		Contact();
		~Contact();
		Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void displayContactInfo() const;
		
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
