/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:49 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/18 20:48:29 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 *   
 */
Phonebook::Phonebook()
{
    contactIndex = 0;
    oldestContact = 0;
}

Phonebook::~Phonebook()
{
    return ;
}

/** 
    Keeps track of index -> OldContactAddress
	Once full -> Index increases  -> Wrapped
	around modulo operator -> Replaces the oldest
	contact with the new one
	
**/

void Phonebook::addInfo()
{
    if (contactIndex >= 8)
	{
        oldestContact = (oldestContact + 1) % 8;
    }
    Contact newContact;
	newContact.addInfo();
    contacts[contactIndex % 8] = newContact;
    contactIndex++;
}

/** 
& is here passed by reference not by value

-> Func receives actual memory add of var pass in from calling fnc,instead of copy of its value.
-> Benefit: Modify value of var directly without separating copy of var.
        -> Reduce memory usage + improves performance with large obj/arrays
**/

void Phonebook::getUserInput(bool& displayAllContacts, int& contactIndexToDisplay) const
{
	std::cout << "Enter desired index value of the contact or type 'show' to display all contacts:";

	std::string userInput;
	std::getline(std::cin, userInput);
	if (userInput == "show")
		displayAllContacts = true;
	else
		contactIndexToDisplay = std::atoi(userInput.c_str());
}


void Phonebook::displayAllContactsInPhonebook() const
{
	int i = 0;
	while (i < contactIndex)
	{
		std::cout << "[" << i + 1 << "]";
		
		if (contacts[i].displayContact())
		{
			std::cout << "Contact is empty" << std::endl;
		}
		else
		{
			contacts[i].displayContact();
		}
		std::cout << std::endl;
		i++;
	}
}


/** 
Supports input validation, retrieves info if it exists and returns
provides info for incorrect input or out of range indices.
**/

void Phonebook::search() const
{
	if (contactIndex == 0)
	{
		std::cout << "No Contacts found\n";
		return ;
	}

	bool displayAllContacts = false;
	int contactIndexToDisplay = -1;

	getUserInput(displayAllContacts, contactIndexToDisplay);
    
	if (displayAllContacts)
	{
		displayAllContactsInPhonebook();
	}
	else
	{
		if (contactIndexToDisplay >= 0 && contactIndexToDisplay < contactIndex)
			contacts[contactIndexToDisplay].displayContact();
		else
			std::cout << "Invalid index. Please enter a valid index value," << std::endl;
	}

}
