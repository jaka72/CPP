#include <iostream>
#include <iomanip>   
#include "Fixed.hpp"
// #include "Car.hpp"

/*	////// EXPLANATION: ////////////////////////////////////////

	THE OBJECT ALWAYS TAKES AN INT OR A FLOAT IN THE ARG.
	IF A FLOAT, IT IS SAVED INTO THE PRIVE VARIABLE fpn, CONVERTED TO INTEGER:
		CONVERSION: the float * 256		(256 == 1 << 8 (fract.bits))
			For example: 	Fixed a(0.5)
							0.5 * 256     = 128
			So, this 128 can be then reversed back into the float,
			by dividing it with 256.
			The powers of 2 are always nice (0.5, 0.25 ... etc.)
			Others are simply rounded up or down:	Fixed b( 0.123 )
			Some floats cannot be nicely converted back to float:
					0.222 * 256 = 56.832 == rounded => 57
											57 / 256 = 0.222656
					2.7   * 256 = 691.2  == rounded => 691
											691 / 256 = 2.699

	WHEN THE OBJECT IS USED TOGETHER WITH std::cout << a
		(ie: being printed)
		THEN IT WILL AUTOM. CALL THE toFloat() FUNCTION, WHICH
		RETURNS THE FLOAT VALUE. THEN IT IS STREAMED INTO THE LEFT
		PARAMETER ostream.
		SO IT WILL PRINT OUT THE FLOAT VALUE FROM THE OBJECT
*/











int	main()
{
// TESTS FROM EX01:
/*
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f ); // same as a = c;
	
	Fixed aa(2.1234567f); // aa = 2.125 // HOW ONLY 3 FRACTIONS ???
	Fixed const same (aa * aa);
	std::cout << "aa is " << aa << "\n";

	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << '\n';
	std::cout << "d is " << d << "\n\n";
	std::cout << "same is " << same << '\n';
	
	std::cout << "a is " << std::setw(6) << a.toInt() << " as integer\n";
	std::cout << "b is " << std::setw(6) << b.toInt() << " as integer\n";
	std::cout << "c is " << std::setw(6) << c.toInt() << " as integer\n";
	std::cout << "d is " << std::setw(6) << d.toInt() << " as integer\n\n";
*/

//	TESTS FOR EX02 

	// Fixed const add_int (Fixed(5) + Fixed(2));
	// Fixed const add_float (Fixed(5.3f) + Fixed(2.1f));
	// std::cout << "add_int is " << add_int << '\n';
	// std::cout << "add_float is " << add_float << '\n';
	
	// Fixed const sub_int (Fixed(2) - Fixed(5));
	// Fixed const sub_float (Fixed(2.1f) - Fixed(5.6f));
	// std::cout << "sub_int is " << sub_int << '\n';
	// std::cout << "sub_float is " << sub_float << '\n';
	
	// Fixed const mul_int (Fixed(5.05f) * Fixed(2.1f));
	// Fixed const mul_float (Fixed(5) * Fixed(2));
	// std::cout << "mul_int is " << mul_int << '\n';
	// std::cout << "mul_float is " << mul_float << '\n';

	// INT / FLOAT
	// Fixed const mul_int (Fixed(5) * Fixed(2.1f));
	// Fixed const mul_float (Fixed(5) * Fixed(2));
	// std::cout << "mul_int is " << mul_int << '\n';
	// std::cout << "mul_float is " << mul_float << '\n';

	// Fixed const div_int (Fixed(12) / Fixed(3));
	// Fixed const div_float (Fixed(10.0f) / Fixed(4.0f));
	// std::cout << "div_int is " << div_int << '\n';
	// std::cout << "div_float is " << div_float << '\n';
	
	std::cout << "\n";


	// COMPARISSON
	// Fixed x{33};
	// Fixed y{44};
	// std::cout << "Is less: " << (y < x) << "  :isless\n";


//////////////////////////////////////////////////////////////////////////////


//Fixed b( a );	// ALSO OK: Fixed b = a
// //	Fixed b { a };	// Is it ok?
// 	Fixed c;
// 	c = b;

// 	std::cout << a.getRawBits() << '\n';
// 	std::cout << b.getRawBits() << '\n';
// 	std::cout << c.getRawBits() << '\n';
	

	std::cout << "\n";



	// Fixed x{ 0 };
	//std::cout << "Increments:  " << x++ << "  ==>end \n";
	//std::cout << "Increments:  " << x << "  ==>end \n";

	// Fixed a;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// Fixed w{33};
	// Fixed q{88};

	// std::cout << "min:  " << Fixed::min(w, q) << " :min \n";


	// FROM SUBJECT EX02
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
