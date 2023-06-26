/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:40:17 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/26 22:40:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    char caseType;

    std::cout << "What kind of complaint would u like to see?";
    std::cin >> caseType;
    harl.complain(caseType);
    return (0);
}