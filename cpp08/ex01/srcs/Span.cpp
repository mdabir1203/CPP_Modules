/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:18 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/21 11:54:36 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copy assignment operator used for -> dynamic data -> 
// Span class stores its data -> dynamic array 
// without using the *this -> copy of entire dynamic array -> inefficient memory leaks 

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "../includes/Span.hpp"


Span::Span(uint64_t N) : max_size(N), storage(0) {};

Span::Span(const Span &to_copy) {
	*this = to_copy;
}

Span &Span::operator=(const Span &to_copy)
{
	this->max_size = to_copy.max_size;
	this->storage = to_copy.storage;
	return *this;
}

Span::~Span(void) {};

void Span::addNumber(int nbr)
{
	if (this->storage.size() == this->max_size)
		throw Span::BeyondMaxSize();
	this->storage.push_back(nbr);
}

// add maximum range to 4,294,967,295  -> uint42_t
// Adds more to uint64_t -> 0 to 18,446,744,073,709,551,615 

void Span::addRandomNumbers(uint64_t quantity)
{
	srand(time(NULL));
	try {
		for (uint64_t i = 0; i < quantity; i += 1)
			this->addNumber(rand());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	std::sort(v.begin(), v.end());
	int shortest_gap = v.at(1) - v.at(0);

	std::vector<int>::iterator i;
	for (i = v.begin(); i != v.end() - 1; i += 1)
	{
		if (abs(*(i + 1) - *i) < shortest_gap)
			shortest_gap = abs(*(i + 1) - *i); 
	}
	return shortest_gap;
}

int Span::longestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2)
		throw Span::NotEnoughElementsException();

	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());

	return abs(max - min);
}

void Span::printStorage(void)
{
	std::vector<int> v = this->storage;
	std::vector<int>::iterator i;

	std::cout << "storage = ";
	for (i = v.begin(); i != v.end(); i += 1)
		std::cout << *i << " ";
	std::cout << std::endl;
}

char const* Span::BeyondMaxSize::what(void) const throw() {
	return "Beyond vector's max size";
}

char const* Span::NotEnoughElementsException::what(void) const throw() {
	return "Vector must have at least 2 elements";
}
