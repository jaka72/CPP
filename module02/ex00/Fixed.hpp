#ifndef FIXED_H
#define FIXED_H

#include <iostream>

// fpn 			= fixed point number
// frac_bits 	= fractional bits 
class Fixed
{
	private:
		int	fpn_prive;

		static const int frac_bits {8};

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
