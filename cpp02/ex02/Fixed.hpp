/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:49:46 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/03 22:06:26 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int FixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
        Fixed(const int val);
        Fixed(const float val);
		Fixed(const Fixed& val);
		~Fixed();
        int getFixedPointValue(void) const { return FixedPointValue; };
        //overloading comparison operators
        Fixed operator=(const Fixed& rhs);
        Fixed operator+(const Fixed& rhs);
        Fixed operator-(const Fixed& rhs);
        Fixed operator*(const Fixed& rhs);
        Fixed operator/(const Fixed& rhs);

        bool operator==(const Fixed& operatorVal) const;
        bool operator!=(const Fixed& operatorVal) const;
        bool operator<=(const Fixed& operatorVal) const;
        bool operator>=(const Fixed& operatorVal) const;
        bool operator<(const Fixed& operatorVal) const;
        bool operator>(const Fixed& operatorVal) const;

        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int val);
        Fixed operator--(int val);
        
        /* getters and setters */
        int getRawBits(void) const;
        void setRawBits(int const raw);

        /* min and max fnc */
        static const Fixed& min(Fixed const &operatorVal1, Fixed const &operatorVal2);
        static const Fixed& max(Fixed const &operatorVal1, Fixed const &operatorVal2);
        
        /** conversion to int and float*/
        float toFloat(void) const;
        int toInt(void) const;





};

/**
 * This non-member fnc uses the insertion operator to add in the val
 * received by the  getter function 
 */
std::ostream& operator << (std::ostream& outputVal, const Fixed& fpVal);

#endif
