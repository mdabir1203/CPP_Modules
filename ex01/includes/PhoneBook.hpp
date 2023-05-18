/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:46:21 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/18 04:08:54 by mabbas           ###   ########.fr       */
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
    
        void addInfo();
        void search() const;
        void getUserInput(bool& displayAllContacts, int& contactIndexToDisplay) const;
        void displayAllContactsInPhonebook() const;
    
    private:
        Contact contacts[8];
        int     contactIndex;
        int     oldestContact;   

};

#endif
