/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:46:21 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 16:56:33 by mabbas           ###   ########.fr       */
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
    
        void add();
        void search() const;
    
    private:
        Contact contacts[8];
        int     contactIndex;
        int     oldestContact;   

};

#endif