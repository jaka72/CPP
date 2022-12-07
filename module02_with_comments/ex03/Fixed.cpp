#include "Fixed.hpp"
#include <cmath>

// const int Fixed::frac_bits = 8;	// why would this be better then 
									// inside class definition ???


// DEFAULT CONSTRUCTOR
// Also good: Fixed::Fixed()  :  fpn_prive = 0
Fixed::Fixed()
{
	//std::cout << "Default constructor called\n"; 
	fpn_prive = 0;
}


// COPY CONSTRUCTOR
	/* IT MAKES ANOTHER INSTANCE OF THE SAME CLASS
		Fixed a();
		Fixed b(a);
	CAN GET THE VALUES FROM THE DEFAULT CONSTRUCTOR,
	OR IT CAN GET ITS OWN VALUES  */
Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called\n"; 
	//fpn_prive = fixed.fpn_prive;	// from the default
	// fpn_prive = 44;						// Its own new value

	// IT CAN BE SIMPLER. In this case you need the Copy Ass. overload for =
		*this = fixed;
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	fpn_prive = i << frac_bits; // same as i * 256
	// OR
	// fpn_prive = std::round(i * (1 << frac_bits));
	// std::cout << "   fpn=" << fpn_prive << "\n";
}

// A CONSTRUCTOR FOR ARG. FLOAT
// Bit shifting can not be used on floats, so it has to be multiplied
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	fpn_prive = round(f * (1 << frac_bits));	
	std::cout << "Converted from float " << f << " to fixed point: " << fpn_prive << "\n\n";
	// fpn_prive = round(f * 256);	
	// std::cout << "Converted from float " << f << " to fixed point: " << fpn_prive << '\n';
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
	//std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
	this->fpn_prive = orig.fpn_prive;
		// IS THIS THE SAME?  WHY WOULD YOU HERE USE getRawBits()  ???
		// 		this->fpn_prive = orig.getrawBits();
	return (*this);
}




// DESTRUCTOR
Fixed::~Fixed()
{
	// std::cout << "Destructor FIXED\n";
}


//	SETTER
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n"; 
	fpn_prive = raw;
	//Fixed::fpn_prive = raw;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n"; 
	return fpn_prive;
}


// PUBLIC MEMBER FUNCTIONS
float Fixed::toFloat(void) const
{
	float a;
	a = fpn_prive / (float)(1 << frac_bits); // MUST BE CASTED TO FLOAT !!!
	//std::cout << " .... called toFloat: a=" << a << " ...\n";
	return (a);
}
		
float Fixed::toInt(void) const
{
	//std::cout << " .... called toInt: fpn=" << fpn_prive << '\n';
	int a;
	a = fpn_prive >> this->frac_bits;
	// ALSO POSSIBLE:
	// a = fpn_prive / (1 << frac_bits);
	return (a);
}


// OVERLOAD FOR THE << OPERATOR, for printing and converting the 
//	fpn value from the object.
//	The return type is ostream.
//	The function name operator<< must have the &	?????
std::ostream &operator<< (std::ostream &out, Fixed const &f)
{
//	out << "    ... called << overload:\n";
	 out << f.toFloat();
	//out << f.toInt();
	// out << (f.getRawBits() / 256);
	return (out);
}



/*


*/