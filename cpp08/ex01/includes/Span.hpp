/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:12 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/12 11:18:45 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <exception>
# include <vector>

class Span {
	public:
		Span(uint64_t N);
		Span(const Span &to_copy);
		Span &operator=(const Span& to_copy);
		~Span(void);

		void addNumber(int nbr);
		void addRandomNumbers(uint64_t quantity);
		int shortestSpan(void);
		int longestSpan(void);

		void printStorage(void);

		class NotEnoughElementsException : public std::exception {
			public:
				char const* what() const throw();
		};
		
		class BeyondMaxSize : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		uint64_t max_size;
		std::vector<int> storage;
		Span();
};

#endif // SPAN_HPP