/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:35 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/01 11:20:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// fpn 			= fixed point number
// fractionalBits 	= fractional bits 
class Fixed
{
	private:
		int	_fixedPointNumber;

		static const int fractionalBits = 8;

	public:
		// default constructor
			Fixed();
					
		// copy constructor
			Fixed(const Fixed& f1);

		// copy assignment operator overload
			Fixed &operator= (const Fixed &orig);

		// destructor
			~Fixed();

		// Setter
			void	setRawBits(int const raw);
		
		// Getter
			int 	getRawBits(void) const;
};

#endif
