/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:32:32 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 16:58:39 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"

/** Create a constructor -> Call from similar class
    
 **/

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


void Contact::displayAll() const
{
    std::cout << std::right << std::setw(10) << idx
              << std::setw(10) << _formatInfo(_firstName)
              << std::setw(10) << _formatInfo(_lastName)
              << std::setw(10) << _formatInfo(_nickName)
              << std::endl;
}

/** Chose to keep this function due to design patterns 
    Making a distinction between Public and Private 
**/
std::string Contact::_addInfo(std::string text) const
{
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}

std::string Contact::_formatInfo(std::string info) const
{
    return (info.length() > 10) ? info.substr(0,9) + "." : info;
}
