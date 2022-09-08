#include <iostream>
#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b( a );	// ALSO OK: Fixed b = a
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';

}
