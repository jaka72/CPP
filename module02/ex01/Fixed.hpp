#ifndef FIXED_H
#define FIXED_H

#include <iostream>



// fpn 			= fixed point number
// frac_bits 	= fractional bits 
class Fixed
{
	private:
		int					fpn_prive;
		static const int	frac_bits {8};

	public:
		// default constructor
			Fixed();
					
		// copy constructor
			Fixed(const Fixed& f1);


		// A CONSTRUCTOR THAT TAKES const int AS PARAMETER
			Fixed(const int i);

		// A CONSTRUCTOR THAT TAKES const float AS PARAMETER
			Fixed(const float f);

		// copy assignment overload
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
//		std::cout << "Original value is " << f1 << '\n';
std::ostream &operator<<(std::ostream &out, const  Fixed &f);


#endif
