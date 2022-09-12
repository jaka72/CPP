#include "Fixed.hpp"
#include <cmath>

// const int Fixed::frac_bits = 8;	// why would this be better then 
									// inside class definition ???


// DO WE NEED PROTECTION FROM TWO SAME OBJECTS ON EACH SIDE ???
//		or it probably is only necessary for the = operator





////////////////////////////////////////////////////////////////////////////////////
// NEW FOR EX02 ////////////////////////////////////////////////////////////////////


// COMPARISSON
// variation A)
bool	Fixed::operator== (const Fixed &fixed)
{
	//std::cout << "From operator== " << this->fpn_prive / 256 << "\n";
	return (this->fpn_prive == fixed.fpn_prive);
}

// variation B)
// NOT POSSIBLE
//	TO HAVE 2 ARGS IS MAYBE ONLY POSSIBLE WITH A FRIEND ????
// bool	Fixed::operator== (const Fixed &f1, const Fixed &f2)
// {
// 	return (f1.fpn_prive == f2.fpn_prive);
// }

bool	Fixed::operator!= (const Fixed &fixed)
{
	return (this->fpn_prive != fixed.fpn_prive);
}

bool	Fixed::operator< (const Fixed &fixed)
{
	return (this->fpn_prive < fixed.fpn_prive);
}

bool	Fixed::operator> (const Fixed &fixed)
{
	return (this->fpn_prive > fixed.fpn_prive);
}

bool	Fixed::operator<= (const Fixed &fixed)
{
	return (this->fpn_prive <= fixed.fpn_prive);
}

bool	Fixed::operator>= (const Fixed &fixed)
{
	return (this->fpn_prive >= fixed.fpn_prive);
}

// INCREMENTS
Fixed Fixed::operator++ ()
{
	++this->fpn_prive;
	return (*this);
}

Fixed Fixed::operator-- ()
{
	--this->fpn_prive;
	return (*this);
}

// WHY WOULD PRE- AND -POST NEED TO BE DIFFERENT ???
Fixed Fixed::operator++ (int)	// post-increment
{
	this->fpn_prive++;
	return (*this);
}

Fixed Fixed::operator-- (int)
{
	this->fpn_prive--;
	return (*this);
}

// WHY WOULD THIS VARIATION BE MORE CORRECT ??? 
		// Fixed	Fixed::operator++(int)
		// {
		// 	Fixed tmp = *this;
		// 	//std::cout << "this: " << this->fpn_prive << ".  tmp: " << tmp.fpn_prive << '\n';
		// 	++this->fpn_prive;
		// 	//std::cout << "this: " << this->fpn_prive << ".  tmp: " << tmp.fpn_prive << '\n';
		// 	return (tmp);
		// }


// ARITHMETIC OPERATORS //////////////////////////////

// !!! IT HAS TO BE SHIFTED BACK TO >> frac_bits  ( / 256), BECAUSE 
//	IT WAS SHIFTED << frac_bits ( * 256) IN THE CONASTRUCTOR(int) 
Fixed Fixed::operator* (const Fixed &fixed)
{
	Fixed temp;
	temp.fpn_prive = (fpn_prive * fixed.fpn_prive) >> frac_bits;
	return temp;

	// Can also be without the temp:
	//	this->fpn_prive = fpn_prive + fixed.fpn_prive;
	//	return *this;
}


// BOTH FLOAT VALUES BECAME INTS IN THE CONSTRUCTOR (via shifting * 256 ). 
//	SO NOW THEY MUST BE CAST BACK TO FLOAT, TO BE CORRECTLY DIVIDED. 
//	THE RESULT MUST BE AGAIN SHIFTED ( * 256) TO INT, BECAUSE FINALY IT
//	WILL BE PRINTED VIA toFloat() --> SHIFTED BACK TO FLOAT  
Fixed Fixed::operator/ (const Fixed &fixed)
{
	Fixed temp;
	float temp_float;

	if (fixed.fpn_prive == 0)  // protection for zero division
	{
		std::cout << "Cannot divide by zero.\n";
		return *this;
	}
	// std::cout << "   this.fpn: " << (this->fpn_prive / 256) << "\n"; 
	// std::cout << "   fixed.fpn: " << (fixed.fpn_prive / 256) << "\n"; 

	temp_float = (float)this->fpn_prive / (float)fixed.fpn_prive;
	temp.fpn_prive = (int)(temp_float * (1 << frac_bits));
	return temp;

}

Fixed Fixed::operator+ (const Fixed &fixed)
{
	Fixed temp;
	temp.fpn_prive = fpn_prive + fixed.fpn_prive;
	return temp;

	// Could also be without the temp:
	//	this->fpn_prive = fpn_prive + fixed.fpn_prive;
	//	return *this;
}

Fixed Fixed::operator- (const Fixed &fixed)
{
	Fixed temp;
	temp.fpn_prive = fpn_prive - fixed.fpn_prive;
	return temp;
}

////////////////////////////////////////////////////////////////////////////////////



// DEFAULT CONSTRUCTOR
// Also good: Fixed::Fixed()  :  fpn_prive = 0
Fixed::Fixed()
{
	std::cout << "Default constructor called\n"; 
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
	std::cout << "Copy constructor called\n"; 
	//fpn_prive = fixed.fpn_prive;	// from the default
	// fpn_prive = 44;						// Its own new value

	// IT CAN BE SIMPLER. In this case you need the Copy Ass. overload for =
		*this = fixed;
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	//std::cout << "      xxx" << fpn_prive << "\n";
	fpn_prive = i << frac_bits; // same as i * 256
	//std::cout << "      XXX" << fpn_prive << "\n";
	// OR
	// fpn_prive = std::round(i * (1 << frac_bits));
	// std::cout << "   fpn=" << fpn_prive << "\n";
}


// A CONSTRUCTOR FOR ARG. FLOAT
// Bit shifting can not be used on floats, so it has to be multiplied
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	fpn_prive = std::round(f * (1 << frac_bits));	
	std::cout << "      current fpn: " << fpn_prive << '\n';
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
	this->fpn_prive = orig.fpn_prive;
		// IS THIS THE SAME?  WHY WOULD YOU HERE USE getRawBits()  ???
		// 		this->fpn_prive = orig.getrawBits();
	return (*this);
}


// DESTRUCTOR
Fixed::~Fixed()
{
//	std::cout << "Destructor called\n"; 
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
	//std::cout << " .... called toFloat: fpn=" << fpn_prive << " ...\n";
	a = fpn_prive / (float)(1 << frac_bits); // MUST BE CASTED TO FLOAT !!!
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
std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	//std::cout << "... " << f.getRawBits() << " ...\n";
	//std::cout << "... " << f.toFloat() << " ...\n";



	out << f.toFloat();
	return (out);
}
