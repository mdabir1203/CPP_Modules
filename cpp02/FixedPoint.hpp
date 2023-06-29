/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:40:42 by mabbas            #+#    #+#             */
/*   Updated: 2023/06/29 13:32:55 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * We have to define copy assignment operator in header otherwise gives an error
 */
class FixedPoint
{
	private:
		int FixedPointValue;
		static const int fractionalBits = 8;
	public:
		FixedPoint();
		FixedPoint(const FixedPoint& val);
        FixedPoint& operator = (const FixedPoint& operatorVal)
        {
            if (this != &operatorVal)
            {
                FixedPointValue = operatorVal.FixedPointValue;
                std::cout << "Copy assignment operator called" << std::endl;
            }
        
            return *this;
        };
		~FixedPoint();
		int getRawBits(void) const;
		void setRawBits(int const raw);

};







