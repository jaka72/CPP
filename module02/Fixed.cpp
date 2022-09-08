#include "Fixed.hpp"

// COPY CONSTRUCTOR (must go outside of class !!)
Fixed::Fixed(const Fixed& f1)
{
	std::cout << "Copy constructor called\n"; 
	fpn_value_prive = f1.fpn_value_prive;
}



// DEFAULT CONSTRUCTOR
Fixed::Fixed()
{
	std::cout << "Default constructor called\n"; 
	fpn_value_prive = 33;
}




void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n"; 
	fpn_value_prive = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n"; 
	return fpn_value_prive;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n"; 
}
