/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:49 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 02:17:33 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

/*********************************/

PhoneBook::PhoneBook(void)
{
    this->_ContactIndex = 0;
    this->_oldestContact = 0;
}

Phonebook::~PhoneBook(void)
{
    return ;
}

void PhoneBook::add(void)
{
    Contact _newContact;
    
    new_contact.add();
    if (this->_contactIndex >= 8)
        this->_oldestContact = 0;
    this->_contacts[this->_contactIndex] = _newContact;
    this->_newContact++;
}

void PhoneBook::search(void) const
{
    std::string _requestedContact;
    
    int idx = 0;
    while (idx++  < 8)
    {
        std::cout << std::setWidth(10) << "|";
        this->_contacts[idx].displayContact();
    }

    std::cout << "Enter desired index value of contact";
    std::getline(std::cin, desiredContact);
    if (_requestedContact[0] >= '0' && _requestedContact[0] <= '7' && _requiredContact.size() == 1)
        this->_contacts[_requestedContact[0] - '0'].displayAll();
    else
        std::cout << "[Bruh !! Invalid Index.. Try again]" << std::endl;
}