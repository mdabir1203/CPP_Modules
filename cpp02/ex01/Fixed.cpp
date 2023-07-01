/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:23:55 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/01 16:23:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    FixedPointValue = val << fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : FixedPointValue((int) (roundf(val * (1 << fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& val) : FixedPointValue(val.FixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

/* For conversion of floating point val FixedPoint val divided
* by scaling factor : no of fractional bits in fixed point representation
*/
float Fixed::toFloat(void) const
{
    return ((float)FixedPointValue / (1 << fractionalBits));
}
/*Right-shifting fractional bit removes the fractional parts
Alternative way : raising 2 to the power of fractional bits(2^8 = 256)
*/
int Fixed::toInt(void) const
{
    return (FixedPointValue >> fractionalBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return FixedPointValue;
}

void Fixed::setRawBits(int rawBits)
{
    FixedPointValue = rawBits;
}

std::ostream& operator << (std::ostream& outputVal, const Fixed& fpVal)
{
    outputVal << fpVal.getFixedPointValue();
    return outputVal;
}


