/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 10:33:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:22:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <iomanip>   
# include <cmath>


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

		// copy assignment overload for the =
		Fixed &operator= (const Fixed &orig);

		// destructor
		~Fixed();

		// Setter
		void	setRawBits(int const raw);
		
		// Getter
		int 	getRawBits(void) const;

		// PUBLIC MEMBER FUNCTIONS
		float toFloat(void) const;
		float toInt(void) const;

		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);

		// ARITHMETIC OPERATORS OVERLOAD
		Fixed operator* (const Fixed &fixed);
		Fixed operator/ (const Fixed &fixed);
		Fixed operator+ (const Fixed &fixed);
		Fixed operator- (const Fixed &fixed);

		// COMPARISSON OPERATORS OVERLOAD
		bool operator<  (const Fixed fixed) const;
		bool operator>  (const Fixed &fixed) const;
		bool operator<= (const Fixed &fixed) const;
		bool operator>= (const Fixed &fixed) const;
		bool operator== (const Fixed &fixed) const;
		bool operator!= (const Fixed &fixed) const;

		// INCREMENT OPERATORS OVERLOAD
		//	pre-increment
		Fixed operator++ ();
		Fixed operator-- ();
		//	post-increment
		Fixed operator++ (int);
		Fixed operator-- (int);
};

// OVERLOAD FOR THE OPERATOR<<  ,WHEN USED WITH std:ostream AND Fixed
std::ostream &operator<< (std::ostream &out, const Fixed &f);

#endif
