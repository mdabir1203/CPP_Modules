/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:20:10 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/23 01:26:18 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


std::string readContentsFromFile(const std::string& filename);
std::string replaceSubstring(const std::string& input, const std::string& s1, const std::string& s2);
void writeContentsToFile(const std::string& filename, const std::string& modifiedrdInput);
void replaceSED(std::string& filename, std::string& s1, std::string& s2);

#endif
