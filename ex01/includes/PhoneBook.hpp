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
#include <sstream>

#define MAX_CONTACTS 8


class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();
    
        void addNewContact();
        void searchContact() const;
        void displayContacts() const;
        void displayContactsList() const;
    
    private:
        Contact contacts[MAX_CONTACTS];
        int     curIdx;
};

#endif