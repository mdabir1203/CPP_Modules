/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:09:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/15 01:10:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"
#include "includes/PhoneBook.hpp"
#include <chrono>
#include <thread>


int main()
{
    Phonebook phonebook;
    std::string    cmd;

    std::cout << "Welcome to my Crappy awesome Phonebook" << std::endl;
    while (1)
    {
        std::cout << "\033[?25l";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\r\033[K";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Enter Any of the three commands ADD, SEARCH or EXIT\n";
        std::getline(std::cin,cmd);
		cmd.erase(std::remove(cmd.begin(),cmd.end(), '\n'), cmd.end());
        if (!cmd.compare("ADD"))
            phonebook.addInfo();
        else if (!cmd.compare("SEARCH"))
            phonebook.search();
        else if (!cmd.compare("EXIT"))
            break;
		else
			std::cout << "Invalid command entered !!" << std::endl;
    }
    return (0);
}
