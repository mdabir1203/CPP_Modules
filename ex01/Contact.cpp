/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:49 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 16:58:53 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/includes/PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 *   
 */
PhoneBook::PhoneBook()
{
    contactIndex = 0;
    oldestContact = 0;
}

Phonebook::~PhoneBook()
{
    return ;
}

/** 
    Once one adds more than 8 it replaces and contact index
    increments to prepare for next contact addition.
**/

void PhoneBook::add()
{   
    newcontact.add();
    if (contactIndex >= 8)
        oldestContact = 0;
    contacts[contactIndex].add();
    contactIndex++;

}


/** 
Supports input validation, retrieves infor if it exists and returns
provides info for incorrect input or out of range indices.
**/
void PhoneBook::search() const
{
    int idx = 0;
	while (idx++ < contactIndex)
    {
        std::cout << std::setw(10) << "|";
		contacts[idx].displayContact();
		idx++;
    }
	
    std::cout << "Enter desired index value of the contact";
    std::string requestedContact;
	std::getline(std::cin, requestedContact);
	
	if (requestedContact.size() == 1 && requestedContact[0] >= '0' && requestedContact[0] <= '7')
    {
		int index = requestedContact[0] - '0';
		if (index < contactIndex)
		{
			contacts[index].displayAll();
		}
		else
		{
			std::cout << "Wrong Index.Try again mate. " << std::endl;
		}
	}
	else
	{
		std::cout << "Wrong Input.Try again mate" << std::endl;
	}

}