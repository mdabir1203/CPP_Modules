/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:37 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/21 11:49:40 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Using DEBUG macro to conditionally test the class 
// have to use DEBUG in makefile to compile to see it
// -> to conditionally compile code that is only needed for debugging,
// -> specific to a particular environment, 
// -> or still under development

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void);
		MutantStack(const MutantStack &to_copy);
		MutantStack &operator=(const MutantStack& to_copy);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] default constructor called" << endl;
	#endif
};

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& to_copy) {
	*this = to_copy;
	#ifdef DEBUG
		std::cout << "[MutantStack] copy constructor called" << endl;
	#endif
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& to_copy)
{
	std::stack<int>::operator=(to_copy);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] default destructor called" << endl;
	#endif
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};

#endif // SPAN_HPP