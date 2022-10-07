#include <iostream>
#include <iomanip>   
#include "Fixed.hpp"

/*	////// EXPLANATION: ////////////////////////////////////////

	Bitwise operator << shift left
		1 << 8	 == 	0000.0001 << 8 = 1.0000.0000  =  256
								( << 7 =   1000.0000  =  128 )
								( << 6 =    100.0000  =   64 )  ... etc

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

			If the initial float is to small, it will produce a zero:
				0.5000 = 128,0 -->rounded to 128
				0.0500 = 12,80 -->rounded to 13
				0.0050 = 1,280 -->rounded to 1
				0.0005 = 0,128 -->rounded to 0
				SMALLER THAN 0,003 IS ROUNDED TO ZERO, SO IT'S USELESS 


	WHEN THE OBJECT IS USED TOGETHER WITH std::cout << a
		(ie: being printed)
		THEN IT WILL AUTOM. CALL THE toFloat() FUNCTION, WHICH
		RETURNS THE FLOAT VALUE. THEN IT IS STREAMED INTO THE LEFT
		PARAMETER ostream.
		SO IT WILL PRINT OUT THE FLOAT VALUE FROM THE OBJECT


		// SHALL THERE BE A PROTECTION FROM OVERFLOWING MAX INT ???
		MAX int to be converted * 256 = 16.777.215    = 4.294.967.040
						--> this is a bit under MAXINT (4.294.967.295)
*/

int	main()
{
	// FROM SUBJECT:

	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	 d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "\n";
	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << '\n';
	std::cout << "c is " << c << '\n';
	std::cout << "d is " << d << "\n\n";
	
	std::cout << "a is " << std::setw(6) << a.toInt() << " as integer\n";
	std::cout << "b is " << std::setw(6) << b.toInt() << " as integer\n";
	std::cout << "c is " << std::setw(6) << c.toInt() << " as integer\n";
	std::cout << "d is " << std::setw(6) << d.toInt() << " as integer\n\n";



//////////////////////////////////////////////////////////////////////////////

	// TESTING
	// Fixed const x0( 5.0f );
	// std::cout << "x0 is " << std::setw(6) << x0.toInt() << " as integer\n";
	// std::cout << "x0 is " << std::setw(6) << x0.toFloat() << " as float\n\n";

	// Fixed const x1( 0.5f );
	// std::cout << "x1 is " << std::setw(6) << x1.toInt() << " as integer\n";
	// std::cout << "x1 is " << std::setw(6) << x1.toFloat() << " as float\n\n";

	// Fixed const x2( 0.05f );
	// std::cout << "x2 is " << std::setw(6) << x2.toInt() << " as integer\n";
	// std::cout << "x2 is " << std::setw(6) << x2.toFloat() << " as float\n\n";

	// Fixed const x3( 0.005f );
	// std::cout << "x3 is " << std::setw(6) << x3.toInt() << " as integer\n";
	// std::cout << "x3 is " << std::setw(6) << x3.toFloat() << " as float\n\n";

	// Fixed const x4( 0.0005f );
	// std::cout << "x4 is " << std::setw(6) << x4.toInt() << " as integer\n";
	// std::cout << "x4 is " << std::setw(6) << x4.toFloat() << " as float\n\n";

}