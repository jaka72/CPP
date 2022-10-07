/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 13:37:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:31:39 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fpn;
		static const int	_frac_bits = 8;

	public:
		// default constructor
		Fixed();
					
		// copy constructor
		Fixed(const Fixed& f1);


		// A CONSTRUCTOR THAT TAKES const int AS PARAMETER
		Fixed(const int i);

		// A CONSTRUCTOR THAT TAKES const float AS PARAMETER
		Fixed(const float f);

		// copy assignment overload for the =
		Fixed &operator=(const Fixed &orig);

		// destructor
		~Fixed();

		// Setter
		void	setRawBits(int const raw);
		
		// Getter
		int 	getRawBits(void) const;

		// Member functions
		float toFloat(void) const;
		float toInt(void) const;
};

// OVERLOAD FOR THE << OPERATOR, WHEN USED WITH std:ostream AND Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
