#ifndef FIXED_H
#define FIXED_H

#include <iostream>

/*
	fpn			= fixed point number
	_frac_bits	= fractional bits
*/
class Fixed
{
	private:
		int					_fpn;
		static const int	_frac_bits = 8;
		int					_increm;

	public:
		// Default constructor
		Fixed();
					
		// Copy constructor
		Fixed(const Fixed& f1);

		// A CONSTRUCTOR WITH int AS PARAMETER
		Fixed(const int i);

		// A CONSTRUCTOR WITH float AS PARAMETER
		Fixed(const float f);

		// ARITHMETIC OPERATORS OVERLOAD
		Fixed operator* (const Fixed &fixed);
		Fixed operator/ (const Fixed &fixed);
		Fixed operator+ (const Fixed &fixed);
		Fixed operator- (const Fixed &fixed);

		// COMPARISSON OPERATORS OVERLOAD
		/*
			TO HAVE 2 ARGS IS ONLY POSSIBLE WITH "friend"
			friend bool operator== (const Fixed &f1, const Fixed &f2);
			
			IF HERE WITHOUT CONST, THEN THE const, THEN min() IS NOT WORKING 
					error: passing ‘const Fixed’ as ‘this’ argument discards qualifiers
			bool operator< (const Fixed fixed) const;
			bool operator< (const Fixed fixed) const;
		*/
		bool operator< (Fixed fixed) const;
		bool operator> (const Fixed &fixed) const;
		bool operator<= (const Fixed &fixed) const;
		bool operator>= (const Fixed &fixed) const;
		bool operator== (const Fixed &fixed) const;
		bool operator!= (const Fixed &fixed) const;

		// INCREMENT OPERATORS OVERLOAD
		//		pre-increment
		Fixed operator++ ();	
		Fixed operator-- ();
		//		post-increment
		Fixed operator++ (int);
		Fixed operator-- (int);
	
	
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

};

// OVERLOAD FOR THE << OPERATOR, WHEN USED WITH std:ostream AND Fixed
std::ostream &operator<< (std::ostream &out, const Fixed &f);

#endif
