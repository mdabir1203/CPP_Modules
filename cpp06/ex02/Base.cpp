/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:35:53 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/19 23:41:56 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Colors.hpp"

Base::~Base()
{
    std::cout << CYAN << "calling the base to destruct" << RESET << std::endl;
}
