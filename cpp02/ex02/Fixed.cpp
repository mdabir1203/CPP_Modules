/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:49:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/03 22:08:27 by mabbas           ###   ########.fr       */
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
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    FixedPointValue = val << fractionalBits;
    //std::cout << "Fixed obj created with Int constructor" << std::endl;
}

Fixed::Fixed(const float val) : FixedPointValue((int) (roundf(val * (1 << fractionalBits))))
{
    //std::cout << "Fixed obj created with Float constructor" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Fixed object destroyed" << std::endl;
}

Fixed::Fixed(const Fixed& val) : FixedPointValue(val.FixedPointValue)
{
    //std::cout << "rhs constructor called" << std::endl;
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

Fixed Fixed::operator=(const Fixed& rhs)
{
    //std::cout << "rhs assignment operator called" << std::endl;
    if (this != &rhs)
    {
        FixedPointValue = rhs.FixedPointValue;
    }
    return *this;
}

/*
If condition in the code is used to check if the current object and the parameter object are the same.
If they are the same, then there is no need to perform the assignment, because it would just overwrite the same value.
This is a common optimization technique to avoid unnecessary work and potential errors.
*/
Fixed Fixed::operator+(const Fixed& rhs)
{
    Fixed	result(this->toFloat() + rhs.toFloat());
    return (result);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
    Fixed	result(this->toFloat() - rhs.toFloat());
    return (result);
}


Fixed Fixed::operator*(const Fixed& rhs)
{
    Fixed	result(this->toFloat() * rhs.toFloat());
    return (result);
}


Fixed Fixed::operator/(const Fixed& rhs)
{
    Fixed	result(this->toFloat() / rhs.toFloat());
    return (result);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

/*postfix increment and decrement*/

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

/*Prefix increment and decrement*/


Fixed	Fixed::operator++(int val)
{
	Fixed	outVal;

	outVal = *this;

	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() + val);
	return (outVal);
}

Fixed	Fixed::operator--(int val)
{
	Fixed	outVal;

	outVal = *this;

	if (!val)
		val = 1;
	this->setRawBits(this->getRawBits() - val);
	return (outVal);
}


const Fixed&	Fixed::min(Fixed const &operatorVal1, Fixed const &operatorVal2)
{
	if (operatorVal1 < operatorVal2)
		return (operatorVal1);
	return (operatorVal2);
}

const Fixed&	Fixed::max(Fixed const &operatorVal1, Fixed const &operatorVal2)
{
	if (operatorVal1 > operatorVal2)
		return (operatorVal1);
	return (operatorVal2);
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
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
