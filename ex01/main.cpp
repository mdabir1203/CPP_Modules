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
#include <chrono>
#include <thread>
#include <iostream>


/* 
Line 24 -> Used to start with clean and empty phonebook
-> Creates a new instance of the phonebook class and assigns
to the variable
-> 41 -> Clear input buffer
*/
int main()
{
    Phonebook phonebook = Phonebook();
    std::string    cmd;

    std::cout << "Welcome to my Crappy awesome Phonebook" << std::endl;
    
    while (true)
    {
        std::cout << "\033[?25l";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\r\033[K";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Enter Any of the three commands ADD, SEARCH or EXIT";
        std::cout << '\n';
        std::getline(std::cin >> std::ws, cmd);
        std::cout << '\n';
		if (cmd == "ADD")
            phonebook.addInfo();
        else if (cmd == "SEARCH")
            phonebook.search();
        else if (cmd == "EXIT")
            exit(0);
		else
        {
            std::cout << "Invalid command entered !!" << std::endl;
            std::cin.ignore(1000, '\n');
        }    
    }
    return (0);
}
