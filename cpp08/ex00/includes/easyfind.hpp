/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:59:50 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/12 10:59:52 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <exception>
# include <algorithm>

class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "easyfind: exception: element not found within container";
   		}
};

template<typename T>
bool easyfind(T& container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) == container.end())
	{
		throw EasyFindException();
		return false;
	}
	else
		return true;
}

#endif // EASYFIND_HPP