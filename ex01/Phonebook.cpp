/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:49 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/25 03:18:41 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/** Fix the issue with parsing in phonebook index 
 *  -> check for edge cases which is not required 
 *  -> 
 * 
 * 
 * 
 *  **/
#include "includes/PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 *   
 */
Phonebook::Phonebook() : currentIndex(0) {}

/** 
    Keeps track of index -> OldContactAddress
	Once full -> Index increases  -> Wrapped
	around modulo operator -> Replaces the oldest
	contact with the new one
	
**/

void Phonebook::addContact(const Contact& newContact)
{
    if (numContacts++ < 8)
	{
		contacts[numContacts] = newContact;
	}
	else
	{
		contacts[8 - 1] = newContact;
	}
	
}

void Phonebook::searchContact(int idx) const
{
	if (idx >= 0 && idx < numContacts)
		contacts[idx].displayContact();
	else
	{
		if (idx < 0)
			std::cout << "Invalid Index. Please enter positive index" << std::endl;
		else if (idx >= numContacts);
			std::cout << "Invalid Index. Out of range" << std::endl;
	}
}

void displayDelimiter(int width, char DelimiterChar) {
    std::string Delimiter(width, DelimiterChar);
    std::cout << Delimiter << std::endl;
}


std::string strTruncate(const std::string& str, int width)
{
	
	if (str.length() <= width)
		return (str);
	else
		return (str.substr(0, width - 1) + ".");

}

void displayHeader(int colW)
{
	std::cout << std::setw(colW) << "Index" << " | ";
	std::cout << std::setw(colW) << "First Name" << " | ";
	std::cout << std::setw(colW) << "Last Name" << " | ";
	std::cout << std::setw(colW) << "Nick Name" << " | " << std::endl;	
}

void Phonebook::displayContacts() const 
{
	int colW 	   = 10;
	int totalWidth = 43; // colW *4 + 3 * 1
	std::string displayDelimiter(totalWidth, '-');
	
	std::cout << std::right << std::setw(totalWidth);
	displayDelimiter(10, '-');

	std::string title = "Phonebook";
	std::cout << std::right << std::setw(totalWidth) << title << std::endl;
	displayDelimiter();
	displayHeader();
	displayDelimiter();
	
	for (int i = 0; i < contacts.size(); i++)
	{
		std::cout << std::right << std::setw(colW) << i << " | ";
		std::cout << std::right << std::setw(colW) << i << strTruncate(contacts[i].getFirstName(), colW)
			<< " | ";
		std::cout << std::right << std::setw(colW) << i << strTruncate(contacts[i].getLastName(), colW)
			<< " | ";
		std::cout << std::right << std::setw(colW) << i << strTruncate(contacts[i].getNickName(), colW) 
			<< std::endl;
	}
	
}






