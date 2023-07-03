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

/**
 * Error faced : 
 *  Dont send raw bits of fp no to output stream
 *  Better send the floating-point representation of the fixed point no
 */

Fixed::Fixed() : FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    FixedPointValue = val << fractionalBits;
    std::cout << "Fixed obj created with Int constructor" << std::endl;
}

Fixed::Fixed(const float val) : FixedPointValue((int) (roundf(val * (1 << fractionalBits))))
{
    std::cout << "Fixed obj created with Float constructor" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed object destroyed" << std::endl;
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

Fixed &Fixed::operator=(const Fixed& operatorVal)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &operatorVal)
    {
        FixedPointValue = operatorVal.FixedPointValue;
    }
    return *this;
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
    return (outputVal << fpVal.toFloat());
}


