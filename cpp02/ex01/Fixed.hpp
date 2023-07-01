/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:19:12 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/01 20:19:12 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:24:13 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/01 16:24:13 by mabbas           ###   ########.fr       */
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
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator = (const Fixed& operatorVal)
        {
            if (this != &operatorVal)
            {
                FixedPointValue = operatorVal.FixedPointValue;
                std::cout << "Copy assignment operator called" << std::endl;
            }
        
            return *this;
        };
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
    int getFixedPointValue(void) const { return FixedPointValue; };
};

/**
 * This non-member fnc uses the insertion operator to add in the val
 * received by the  getter function 
 */
std::ostream& operator << (std::ostream& outputVal, const Fixed& fpVal);

#endif