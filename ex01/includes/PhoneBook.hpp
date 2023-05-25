/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:46:21 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/25 03:18:05 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"


class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();
    
        void addContact();
        void searchContact(int idx) const;
        void displayContacts() const;
    
    private:
        Contact contacts[8];
        int     numContacts;
        std::string strTruncate(const std::string& str, int len) const;
        void displayDelimiter(int width, char DelimiterChar);
};

#endif
