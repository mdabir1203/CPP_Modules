/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:40:42 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/04 03:27:53 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * We have to define copy assignment operator in header otherwise gives an error
 * As this pointer is a non static member
 */
class FixedPoint
{
	private:
		int FixedPointValue;
		static const int fractionalBits = 8;
	public:
		FixedPoint();
		FixedPoint(const FixedPoint& val);
        FixedPoint& operator=(const FixedPoint& operatorVal);
		~FixedPoint();
		int getRawBits(void) const;
		void setRawBits(int const raw);

};







