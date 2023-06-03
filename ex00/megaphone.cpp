/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:39:07 by mabbas            #+#    #+#             */
/*   Updated: 2023/05/10 14:15:23 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
From the project we can infer that it makes from lowecase to uppercase

-> used string object -> represents a seq of characters.
-> Grow/shrink dynamically when needed
-> Provides various methods and operators for manipulating and accessing characters
-> supports different character encodings and locales


-> What did we learn : 
    1. Using headers, libraries in c++
    2. used the reserve function which is from C++ Vector library
    3. 
**/

#include <iostream>
#include <string>
#include <cctype>

/**
 * push_back() function is used to add characrters to the upper_str one by one
 * as they are converted to uppercase
 * reserve to allocate memory before adding chars to it -> avoids frequent reallocation
 * improves performance for large strings 
*/
std::string to_uppercase(const std::string str)
{
    std::string upper_str;
    upper_str.reserve(str.length());
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        upper_str.push_back(std::toupper(str[i]));
    }
    
    return  upper_str;
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::cout << to_uppercase(av[i]);
    }  
    return (0);
}
