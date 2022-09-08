#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// fpn 			= fixed point number
// frac_bits 	= fractional bits 
class Fixed
{
	private:
		int	fpn_value_prive;

		static const int frac_bits {8};

	public:
		Fixed();	// default constructor
					
		// copy constructor
		Fixed(const Fixed& f1);

		// copy assignment overload
		// ...

		~Fixed();	// destructor

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
