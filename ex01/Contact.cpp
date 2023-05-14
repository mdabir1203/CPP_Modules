/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:47:06 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/15 01:07:35 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "includes/Contact.hpp"



Contact::Contact(){idx = 0;}
Contact::~Contact(){}

void Contact::addInfo()
{
    std::cout << "First Name: ";
    _firstName = this->_addInfo("");

    std::cout << "Last Name: ";
    _lastName  = this->_addInfo("Last Name");

    std::cout << "Nick Name: ";
    _nickName  = this->_addInfo("Nick Name");

    std::cout << "Phone Number: ";
    _phoneNumber = this->_addInfo("Phone Number");

    std::cout << "Darkest Secret: ";
    _darkestSecret = this->_addInfo("Darkest Secret");

    std::cout << "Contact added to the phonebook. \n";
}



void Contact::displayContact() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nick Name: " << _nickName << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
    
}



/** Creates similarity like below 
Index      First name     Last name    Nickname
----------------------------------------------------
     1        Abir           Abbas        ab1r 
     2        Mohammad       Melkoly      Mo  
     3        Facinet        Fakyout      Faci   

const -> Used as "read-only" ->Cannot modify once 
initialized.
- Prevents -> Unintentional modifications 
- Improves program correctness and robustness
- Improves Readability and maintainability
- Better optimization and performance : faster execution times

 **/

void Contact::displayAll() const
{
    std::cout << std::right << std::setw(10) << idx
              << std::setw(10) << _formatInfo(_firstName)
              << std::setw(10) << _formatInfo(_lastName)
              << std::setw(10) << _formatInfo(_nickName)
              << std::endl;
}

/** Chose to keep this function due to design patterns 
    Making a distinction between Public and Private Class (_)
**/
std::string Contact::_addInfo(std::string text) const
{
    std::string input;
    std::cout << text << ": ";
    std::getline(std::cin >> std::ws, input);
    return input;
}

/** 
Newspapers often have a limited amount of space for headlines, 
so they need to summarize the main point of an article in a shorter title.
Similarly, if a string is too long, we can summarize it by showing the first few characters
with an added period, [Hey, I really enjoyed reading your article and made points...]
which represents the rest of the string. 

**/

std::string Contact::_formatInfo(std::string info) const
{
    return (info.length() > 10) ? info.substr(0,9) + "." : info;
}
