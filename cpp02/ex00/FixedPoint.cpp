/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:52:15 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/04 03:31:04 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"

FixedPoint::FixedPoint() : FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

FixedPoint::FixedPoint(const FixedPoint& val) : FixedPointValue(val.FixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

FixedPoint &FixedPoint::operator=(const FixedPoint& operatorVal)
{
    if (this != &operatorVal)
    {
        FixedPointValue = operatorVal.FixedPointValue;
        std::cout << "Copy assignment operator called" << std::endl;
    }
        
    return *this;
}

FixedPoint::~FixedPoint()
{
    std::cout << "Destructor called" << std::endl;
}

int FixedPoint::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return FixedPointValue;
}

void FixedPoint::setRawBits(int rawBits)
{
    FixedPointValue = rawBits;
}

