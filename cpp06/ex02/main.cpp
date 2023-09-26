/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:38:24 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/20 00:15:52 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "operations.hpp"

int main(void)
{
    Base    *ptr_b = generate();
    identify(ptr_b);


    //Base    &ref_b = *(generate());
    //identify(*ptr_b);
   
    delete ptr_b; 
    //delete ref_b; 
    
    return (0);
}