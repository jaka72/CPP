#include <iostream>
#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b( a );	// ALSO OK: Fixed b = a
//	Fixed b { a };	// Is it ok?
	Fixed c;


	c = b;


	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';
	
	
	std::cout << c.setRawBits(77) << '\n';
	// std::cout << c.getRawBits() << '\n';

}
