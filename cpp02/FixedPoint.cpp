/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:52:15 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/29 13:30:16 by mabbas           ###   ########.fr       */
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

