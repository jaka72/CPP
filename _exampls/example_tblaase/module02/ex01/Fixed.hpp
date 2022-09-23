
// Header-protection
#pragma once

// Includes
#include <iostream>
#include <cmath>

// classes

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
	// Constructors
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);

	// Deconstructors
		~Fixed();

	// Overloaded Operators
		Fixed &operator=(const Fixed &src);

	// Public Methods
		float toFloat(void)const;
		int toInt(void)const;
	// Getter
		int getRawBits(void)const;
	// Setter
		void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);