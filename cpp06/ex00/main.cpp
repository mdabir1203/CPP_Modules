/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:20:18 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/20 00:20:20 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc,char **argv)
{
  if (argc != 2) {
    std::cout << "Usage: [./convert <char, int, float or double>]" << std::endl;
    return 0;
}
std::string str = argv[1];

ScalarConverter converter = ScalarConverter();
converter.setInput(str);
converter.display();
}
