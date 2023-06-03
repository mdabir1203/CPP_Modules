/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:47:06 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/24 17:32:31 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "includes/Contact.hpp"
#include <iostream>
#include <iomanip>


Contact::Contact(){}
Contact::~Contact(){}


/**
 * Used an initializer list to initialize the class members
 * Helps in initializing complex member variables/ requires specific logic
*/

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret)
    : _firstName(firstName), _lastName(lastName), _nickName(nickname), _phoneNumber(phoneNumber),
      _darkestSecret(darkestSecret) {}

std::string Contact::getFirstName() const { return _firstName; }

std::string Contact::getLastName() const { return _lastName; }

std::string Contact::getNickName() const { return _nickName; }


std::string Contact::getPhoneNumber() const { return _phoneNumber; }

std::string Contact::getDarkestSecret() const { return _darkestSecret; }


void Contact::displayContactInfo() const {
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickName << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
