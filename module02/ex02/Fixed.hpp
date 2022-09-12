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
		///// new for ex02 /////////////////////

		Fixed operator* (const Fixed &fixed);
		Fixed operator/ (const Fixed &fixed);
		Fixed operator+ (const Fixed &fixed);
		Fixed operator- (const Fixed &fixed);

		// COMPARISSON
		// TO HAVE 2 ARGS IS ONLY POSSIBLE WITH "friend"
		// friend bool operator== (const Fixed &f1, const Fixed &f2);
		bool operator< (const Fixed &fixed);
		bool operator> (const Fixed &fixed);
		bool operator<= (const Fixed &fixed);
		bool operator>= (const Fixed &fixed);
		bool operator== (const Fixed &fixed);
		bool operator!= (const Fixed &fixed);

		// INCREMENTS
		//	WHAT IS THE LOGIC WITH OR WITHOUT (int) 	?????
		Fixed operator++ ();	// pre-increment
		Fixed operator-- ();
		Fixed operator++ (int);	// post-increment
		Fixed operator-- (int a);



		// {
		// 	// if (this == &fixed) // protection
		// 		// return *this;
		// 	Fixed temp;
		// 	temp.fpn_prive = fpn_prive + fixed.fpn_prive;
		// 	// Can also be without the temp:
		// 	//	this->fpn_prive = fpn_prive + fixed.fpn_prive;

		// 	return temp;
		// 	// return *this;
		// }


		// Fixed operator*(const Fixed &fixed)
		// {
		// 	// if (this == &fixed) // protection
		// 		// return *this;
		// 	Fixed temp;
		// 	temp.fpn_prive = fpn_prive * fixed.fpn_prive;
		// 	// Can also be without the temp:
		// 	//	this->fpn_prive = fpn_prive + fixed.fpn_prive;

		// 	return temp;
		// 	// return *this;
		// }

		///////////////////////////////////////

		// default constructor
			Fixed();
					
		// copy constructor
			Fixed(const Fixed& f1);


		// A CONSTRUCTOR THAT TAKES const int AS PARAMETER
			Fixed(const int i);

		// A CONSTRUCTOR THAT TAKES const float AS PARAMETER
			Fixed(const float f);

	

	
	
		// copy assignment overload for the =
			Fixed &operator= (const Fixed &orig);

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


// bool Fixed::operator== (const Fixed& f1, const Fixed& f2)
// {
// 	if (f1.fpn_prive == f2.fpn_prive)
// 		return (true);
// 	else
// 		return (false);
// 	// return  (f1.fpn_prive == f2.fpn_prive);
// }



#endif
