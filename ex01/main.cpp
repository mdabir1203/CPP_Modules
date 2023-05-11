/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:09:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/11 17:01:25 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

int main(int ac,char **av)
{
    Phonebook phonebook;
    std::string    cmd;

    std::cout << "Crappy awesome Phonebook" << std::endl;
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin,cmd);
		cmd.erase(std::remove(cmd.begin(),cmd.end(), '\n'), cmd.end());
        if (!cmd.compare("ADD"))
            phonebook.add();
        else if (!cmd.compare("SEARCH"))
            phonebook.search();
        else if (!cmd.compare("EXIT"))
            break;
		else
			std::cout << "Invalid bro !!" << std::endl;
    }
    return (0);
}