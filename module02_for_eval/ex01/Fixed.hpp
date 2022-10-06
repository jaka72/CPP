/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:27:01 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/06 12:27:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
// # include <iomanip> // for precision

// fpn 			= fixed point number
// _frac_bits 	= fractional bits 
class Fixed
{
	private:
		int					_fpn;
		static const int	_frac_bits = 8;

	public:
		// Default constructor
		Fixed();
					
		// Copy constructor
		Fixed(const Fixed& f1);

		// Parameterized constructors
		Fixed(const int i);
		Fixed(const float f);

		// Copy assignment operator= overload
		Fixed &operator=(const Fixed &orig);

		// Destructor
		~Fixed();

		// Setter
		void	setRawBits(int const raw);

		// Getter
		int 	getRawBits(void) const;

		// Member functions
		float toFloat(void) const;
		float toInt(void) const;
};

// OVERLOAD FOR THE OPERATOR<<  ,WHEN USED WITH std:ostream AND Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
