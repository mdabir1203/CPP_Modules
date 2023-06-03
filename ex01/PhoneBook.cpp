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



/** 
 * Learnings to Take: 
 * -> undefined references to functions -> 
 *     declaring a destructor in class and not defining it
 *    -> in easy way no implementaion / body of destructor
 * 
 * 
 *  **/
#include "includes/PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 *   
 */
Phonebook::Phonebook() : curIdx(0){}
Phonebook::~Phonebook(){}

/** 
    Keeps track of index -> OldContactAddress
	Once full -> Index increases  -> Wrapped
	around modulo operator -> Replaces the oldest
	contact with the new one
	
**/
void Phonebook::addNewContact() 
{
	if (curIdx >= MAX_CONTACTS)
	{
		curIdx = 0;
	}
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	std::cout << "Enter nickname: ";
	std::cin >> nickName;
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	contacts[curIdx] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	curIdx++;	

}


void Phonebook::searchContact() const
{
	if (curIdx == 0)
	{
		std::cout << "No contacts to search for" << std::endl;
		return ;
	}

	displayContactsList();
	int idx;
	std::cout << "Enter index value of contact: ";
	std::cin >> idx;
	if (idx < 0 || idx >= curIdx)
	{
		std::cout << "Invalid Index. Please enter positive index" << std::endl;
		return ;
	}
	contacts[idx].displayContactInfo();
}


void Phonebook::displayContactsList() const
{
	std::cout << "Contacts List:\n";
	std::cout << "--------------------------------------------------------------------------\n";
	std::cout << "Index | First Name | Last Name | Nick Name | Phone Number | Darkest Secret\n";
	std::cout << "--------------------------------------------------------------------------\n";
	int i = 0;
	while (++i < MAX_CONTACTS)
	{
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickName = contacts[i].getNickName();
		std::string phoneNumber = contacts[i].getPhoneNumber();
		std::string darkestSecret = contacts[i].getDarkestSecret();

		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(12) << (firstName.length() > 10 ? firstName.substr(0,9) + "." : firstName) << "|";
		std::cout << std::setw(12) << (lastName.length() > 10 ? lastName.substr(0,9) + "." : lastName) << "|";
		std::cout << std::setw(12) << (nickName.length() > 10 ? nickName.substr(0,9) + "." : nickName) << "|";
		std::cout << std::setw(12) << (phoneNumber.length() > 10 ? phoneNumber.substr(0,9) + "." : phoneNumber) << "|";
		std::cout << std::setw(12) << (darkestSecret.length() > 10 ? darkestSecret.substr(0,9) + "." : darkestSecret) << "|";
		std::cout << std::endl;
	}
	std::cout << "------------------------------------------------------------------------------" << std::endl;

}
