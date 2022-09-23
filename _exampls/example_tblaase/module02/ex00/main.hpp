// Header-protection
#pragma once

// Includes
#include <iostream>

// classes

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
	// Constructors
		Fixed();
		Fixed(const Fixed& copy);

	// Deconstructors
		~Fixed();

	// Overloaded Operators
		Fixed &operator=(const Fixed &src);

	// Public Methods

	// Getter
		int getRawBits(void)const;
	// Setter
		void setRawBits(int const raw);

};