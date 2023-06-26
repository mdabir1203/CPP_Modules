/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:11:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/23 15:03:44 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

/** Reading the input files converted as strings */

std::string readContentsFromFile(const std::string& filename)
{
    std::ifstream input(filename);

    if (!input.is_open())
    {
        std::cerr << "Error: Input file can't be opened \"" << filename << "\"" << std::endl;
        return "";
    }
    
    std::stringstream rdInput;
    rdInput << input.rdbuf();

    return rdInput.str();
}

std::string replaceSubstring(const std::string& input, const std::string& s1, const std::string& s2)
{
    std::string modifiedrdInput;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input.substr(i, s1.length()) == s1)
        {
            modifiedrdInput += s2;
            i += s1.length() -1 ; // to skip over matched seq
        }
        else
        {
            modifiedrdInput += input[i];
        }
    }
    return modifiedrdInput;
}

void writeContentsToFile(const std::string& filename, const std::string& modifiedrdInput)
{
    std::ofstream output((filename + ".replace").c_str());
    if (!output.is_open())
    {
        std::cerr << "Error: Couldn't open output file \"" << filename + ".replace" << "\"" << std::endl;
        return ;
    }

    output << modifiedrdInput;   
}

/**
 * @brief 
 * string to pass it as parameters
 * backslash is used to avoid the str literal error
 */
void replaceSED(std::string& filename, std::string& s1, std::string& s2)
{
    std::string rdContents = readContentsFromFile(filename);
    if (rdContents.empty())
        return ;
    std::string modifiedContents = replaceSubstring(rdContents, s1, s2);
    writeContentsToFile(filename, modifiedContents);
}
