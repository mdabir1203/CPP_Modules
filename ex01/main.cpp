/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:09:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/18 04:59:21 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"
#include "includes/PhoneBook.hpp"
#include <stdlib.h>

/* 
  
*/

int main()
{
    Phonebook PhoneBook;
    bool operation = true; 
    std::string cmd;

    std::cout << "Welcome to my Crappy awesome Phonebook" << std::endl;

    while (operation && std::getline(std::cin, cmd))
    {
        if (std::cin.eof() == true)
        {
            std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
            exit(0);
        }
        
        std::cout << "Enter any of the three commands: ADD, SEARCH, or EXIT" << std::endl;
        std::cout << "For Full Contact List: Enter the command: SHOW" << std::endl;

        if (cmd.compare("ADD") == 0)
            PhoneBook.addNewContact();
        else if (cmd.compare("SEARCH") == 0)
            PhoneBook.searchContact();
        else if (cmd.compare("SHOW") == 0)
		    PhoneBook.displayContactsList();
        else if (cmd.compare("EXIT") == 0)
        {
            std::cout << "\033[34mThank you f or tolerating my crappy phonebook. Good Bye.\033[0m" << std::endl;
            operation = false;
            continue ;
        }
        cmd.clear();
    }

    return 0;
}
















