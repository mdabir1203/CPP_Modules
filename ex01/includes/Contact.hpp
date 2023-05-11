/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:39:50 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 01:54:53 by mabbas           ###   ########.fr       */
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
        Contact _contacts[8];
        int     _nbrContact;
        int     _oldestContact;   

};

#endif