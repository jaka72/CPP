#include "Fixed.hpp"

int main(void)
{
	// SUBJECT
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	//a = b;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;


/////////////////////////////////////////////////////////////////////////
	// Fixed a;
	// std::cout << "a is " << a << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	
	// Fixed const b(0.5f);
	// std::cout << "b is " << b << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	
	
	// Fixed const c(42.42f);
	// Fixed const d(b);

	// a = Fixed(1234.4321f);

	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

/////////// JAKA ///////////////////////////////////////////
	// Fixed const aa(11.5f);
	// std::cout << "\naa is " << aa << "\n";
	// std::cout << "aa is " << aa.toInt() << " as integer\n";
	
	//  Fixed const bb(1.0f);			//	256
	//  Fixed const bb(0.5f);			//	128
	// Fixed const bb(0.25f);				//	64
	//  Fixed const bb(0.125f);			// 32
	// Fixed const bb(0.015625f);		// 4
	// Fixed const bb(0.0078125f);		// 2
	// Fixed const bb(0.00390625f);		// 1
	// std::cout << "bb is " << bb << "\n\n";
	// Fixed const cc(1.11f);
	// Fixed const dd(111);

	// Fixed const bb1(2.5f);				//	640
	// Fixed const bb2(25.f);				//	6400
	// Fixed const bb3(1.5f);				//	384 (256 + 128)
	
	// Fixed const bb4(0.0005f);				//	0
	// Fixed const bb5(0.5f);				//	0
	// std::cout << "bb is " << bb5 << "\n\n";
	// std::cout << "bb is " << bb5.toInt() << " as integer\n";



	return 0;
}