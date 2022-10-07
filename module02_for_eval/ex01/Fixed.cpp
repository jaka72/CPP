#include "Fixed.hpp"


// DEFAULT CONSTRUCTOR
// Also good: Fixed::Fixed()  :  _fpn = 0
Fixed::Fixed()
{
	std::cout << "Default constructor called\n"; 
	_fpn = 0;
}


// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n"; 
		*this = fixed;
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	_fpn = i << _frac_bits; // same as i * 256
	// 		OR
	// _fpn = std::round(i * (1 << _frac_bits));
}

// A CONSTRUCTOR FOR ARG. FLOAT
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	_fpn = round(f * (1 << _frac_bits));
	std::cout << "Converted from float " << f << " to fixed point: " << _fpn << '\n';
}


//	COPY ASSIGNMENT OVERLOAD FOR =OPERATOR
/*	
	This is called in cases, when an object is on both sides of = 
			Fixed a;
			a = Fixed(12.34)
				or
			Fixed a;
			Fixed b(12.34);
			a = b;
	Also, if inside the copy constructor it is used the = 
			like: *this = fixed
*/
Fixed &Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
	this->_fpn = orig._fpn;
	return (*this);
}


// DESTRUCTOR
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


//	SETTER
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n"; 
	_fpn = raw;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n"; 
	return _fpn;
}


// PUBLIC MEMBER FUNCTIONS
float Fixed::toFloat(void) const
{
	//std::cout << "Called toFloat() \n";
	float a;
	a = _fpn / (float)(1 << _frac_bits); // MUST BE CASTED TO FLOAT !!!
	return (a);
}
		
float Fixed::toInt(void) const
{
	//std::cout << "Called toInt() \n";
	int a;
	a = _fpn >> this->_frac_bits;
	// 	OR:
	// a = _fpn / (1 << _frac_bits);
	return (a);
}


// OVERLOAD FOR THE OPERATOR<<
std::ostream &operator<< (std::ostream &out, Fixed const &f)
{
	//out << "Called operator<< overload:\n";
	// out << std::fixed << std::setprecision(2) << f.toFloat();
	out << f.toFloat();
	return (out);
}
