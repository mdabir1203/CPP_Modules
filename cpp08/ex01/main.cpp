/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:23 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/21 11:51:06 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"



int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printStorage();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	// Pushing beyond N elements
	try {
		sp.addNumber(42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// Trying to get a span with less than 2 elements on the vector
	Span sp1 = Span(1);
	sp1.addNumber(1);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	Span sp2 = Span(5);

	sp2.addRandomNumbers(5);
	std::cout << "sp2 ";
	sp2.printStorage();
	std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
	return EXIT_SUCCESS;
}
