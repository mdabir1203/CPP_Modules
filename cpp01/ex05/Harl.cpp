/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:16:55 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/23 12:16:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "Debug: I like to use colorful stickers to mark the bugs in my code. It makes them easier to spot and fix." << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info: You delivered the wrong burger to my house. I ordered a cheese and beef, \
    but  you gave me a chicken and chili. How could you make such a mistake?" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning: Example: “I am about to eat a burger that contains beef and cheese. I may be allergic to these ingredients or dislike their taste. Please check your order before delivering." << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error: I am allergic to beef and cheese. I cannot eat this burger. I will have to throw it away." << std::endl;
}


void Harl::complain(char caseType)
{
    void (Harl::*msgType)(void);
    switch (caseType)
    {
        case 'd':
            msgType = &Harl::debug;
            break;
        case 'i':
            msgType = &Harl::info;
            break;
        case 'w':
            msgType = &Harl::warning;
            break;
        case 'e':
            msgType = &Harl::error;
            break;
        default:
            std::cout << "Invalid case" << std::endl;
            return ;
    }
    (this->*msgType)();
}


