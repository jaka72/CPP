#include <iostream>
#include <iomanip>   
#include "Fixed.hpp"

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
							0.123 * 256 = 31.488 == rounded => 31 
							0.222 * 256 = 56.832 == rounded => 57
				This cannot be nicely converted back to float:
							57 / 256 = 0.222656


	WHEN THE OBJECT IS USED TOGETHER WITH std::cout << a
		(ie: being printed)
		THEN IT WILL AUTOM. CALL THE toFloat() FUNCTION, WHICH
		RETURNS THE FLOAT VALUE. THEN IT IS STREAMED INTO THE LEFT
		PARAMETER ostream.
		SO IT WILL PRINT OUT THE FLOAT VALUE FROM THE OBJECT
*/

int	main()
{
	// FROM SUBJECT:

	Fixed a;
	Fixed aa(10);
	// Fixed const b(Fixed(5.05f) * Fixed(2));

	// ?????????? ?????????????????????????
	// THIS b IS DISPLAYED WITHOUT CONVERTED BACK TO >> 8 ?????????????
	Fixed const b (Fixed(5) * Fixed(2));
	// Fixed const b( 10 );
	// Fixed const c( 42.42f );
	// Fixed const d( b );
	// a = Fixed( 1234.4321f ); // same as a = c;
	
	std::cout << "\n";
	std::cout << "a is " << a << "\n";
	std::cout << "aa is " << aa << "\n";
	std::cout << "b is " << b << '\n';
	// std::cout << "c is " << c << '\n';
	// std::cout << "d is " << d << "\n\n";
	
	// std::cout << "a is " << std::setw(6) << a.toInt() << " as integer\n";
	// std::cout << "b is " << std::setw(6) << b.toInt() << " as integer\n";
	// std::cout << "c is " << std::setw(6) << c.toInt() << " as integer\n";
	// std::cout << "d is " << std::setw(6) << d.toInt() << " as integer\n\n";

//////////////////////////////////////////////////////////////////////////////
 	// Fixed a;
	// std::cout << "a is " << a << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;

	// Fixed b(0.5f);
	// std::cout << "b is " << b << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;


 	//Fixed b( a );	// ALSO OK: Fixed b = a
// //	Fixed b { a };	// Is it ok?
// 	Fixed c;


// 	c = b;

// 	std::cout << a.getRawBits() << '\n';
// 	std::cout << b.getRawBits() << '\n';
// 	std::cout << c.getRawBits() << '\n';
	
	
	//std::cout << c.setRawBits(77) << '\n';
	// std::cout << c.getRawBits() << '\n';

	// Fixed d(0.5f);
	// std::cout << d.getRawBits() << '\n';
	
	// std::cout << "A) d is " << d << '\n';

	// std::cout << "B) d is " << d.toInt() << " as integer\n";

}
