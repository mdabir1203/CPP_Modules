/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:59:59 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/21 11:52:00 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "includes/easyfind.hpp"



int main(void)
{
	// VECTOR //
	std::vector<int> vec1;
	for (size_t i = 0; i <= 10; i += 1) {
		vec1.push_back(i);
	}

	std::cout << "vec1 = ";
	for (std::vector<int>::iterator i = vec1.begin(), e = vec1.end(); i != e; i += 1) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// will find
	try {
		easyfind(vec1, 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	// will raise EasyFindException
	try {
		easyfind(vec1, 11);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}
