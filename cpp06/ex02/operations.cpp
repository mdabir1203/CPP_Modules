/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:39:40 by mabbas            #+#    #+#             */
/*   Updated: 2023/09/20 00:14:10 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "operations.hpp"

int generateRandomNbrs(void)
{
    int randomNbr = 0;
    
    srand ( time(NULL) * getpid() );
    randomNbr = (rand() % 3) + 1;
    if (randomNbr < 0)
    {
        randomNbr *= -1;
    }
    return (randomNbr);
    
}


Base *generate(void)
{
    Base    *b = NULL;
    int     randomNbr = generateRandomNbrs();

    switch (randomNbr)
    {
        case 1:
        {
            b = new A;
            break ;
        }
        case 2:
        {
            b = new B;
            break ;
        }
        case 3:
        {
            b = new C;
            break ;
        }
        default:
        {
            std::cout << "Invalid Choice\n";
            break ;
        }
        
    }
    return (b);
}



void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
    if (a != NULL)
    {
        std::cout << "A\n";
    }
    else if (b != NULL)
    {
        std::cout << "B\n";
    }
    else if (c != NULL)
    {
        std::cout << "C\n";
    }
}


void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A\n";
        return ;
    }
    catch( std::exception &bc)
    {
        std::cerr << bc.what() << " to derived class A\n";
    }
    
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B\n";
        return ;
    }
    catch( std::exception &bc)
    {
        std::cerr << bc.what() << " to derived class B\n";
    }
    
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C\n";
        return ;
    }
    catch( std::exception &bc)
    {
        std::cerr << bc.what() << " to derived class C\n";
    }
}