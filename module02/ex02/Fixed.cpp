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
bool	Fixed::operator== (const Fixed &fixed) const
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

bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (this->fpn_prive != fixed.fpn_prive);
}

// !!! HERE IT WAS CAUSING PROBLEMS BECAUSE OF THE COMBINATION  
	// OF THE & AND THE "const" 
	//	 OF PARAMETETRS AND ALSO AFTER FUNCTION NAME ???
	//		ONLY A CERTAIN COMBINATION WORKS.
	//		IT IS ABOUT 2 FUNCTIONS:
	//			1) 	The Fixed::operator<()
	//			2)	The const Fixed &Fixed::min()   --> which uses the operator<() 
	// bool	Fixed::operator< (Fixed fixed) const
	// 	MUST HAVE const AT END, OR THE const min() STOPS WORKING:
	//		error: passing ‘const Fixed’ as ‘this’ argument discards qualifiers
	//		THIS IS BECAUSE THE min(const ...) function must have "const args" due to the subject!
	// 		SO THE LEFT ARG THAT COMES INTO THE <function MUST ALSO BE const! 
// bool	Fixed::operator< (const Fixed fixed) const
bool	Fixed::operator< (Fixed fixed) const
{
	return (this->fpn_prive < fixed.fpn_prive);
}

bool	Fixed::operator> (const Fixed &fixed) const
{
	return (this->fpn_prive > fixed.fpn_prive);
}

bool	Fixed::operator<= (const Fixed &fixed) const
{
	return (this->fpn_prive <= fixed.fpn_prive);
}

bool	Fixed::operator>= (const Fixed &fixed) const
{
	return (this->fpn_prive >= fixed.fpn_prive);
}

// INCREMENTS ////////////////////////////////////////////////////////
// PRE- AND -POST NEED TO BE DIFFERENT !!
/*
	See 14.8 learncpp
	The C++ language increment specification has a special case:
	The compiler checks if the overloaded operator has an int parameter.
	Therefore we need to provide a dummy int parameter, for the post-incr.
	If the overloaded operator has an int parameter, the operator is 
	a postfix overload. If the overloaded operator has no parameter, 
	the operator is a prefix overload.

	So it returns temp with not-yet incremented value: 
	Digit Digit::operator++ (int)		// POST-INCREMENT
	{
		Digit temp {*this};
		std::cout << "This Before: " << this->m_digit << '\n';	// 44
		std::cout << "Temp Before: " << temp.m_digit << '\n';	// 44
		++this->m_digit;
		std::cout << "This after: " << this->m_digit << '\n';	// 45
		std::cout << "Temp after: " << temp.m_digit << '\n';	// 44
		return (temp);
	}

*/

Fixed Fixed::operator++ ()	// PRE-INCREMENT
{
	++this->fpn_prive;
	return (*this);
}

Fixed Fixed::operator-- ()
{
	--this->fpn_prive;
	return (*this);
}

Fixed Fixed::operator++ (int)		// POST-INCREMENT
{
	Fixed temp {*this};
	//std::cout << "this: " << this->fpn_prive << ".  tmp: " << tmp.fpn_prive << '\n';
	++this->fpn_prive;
	//std::cout << "this: " << this->fpn_prive << ".  tmp: " << tmp.fpn_prive << '\n';
	return (temp);
}

Fixed Fixed::operator-- (int)		// POST-INCREMENT
{
	Fixed temp = *this;
	--this->fpn_prive;
	return (temp);
}


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


Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

// const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
//	HERE IT WAS A PROBLEM WITH THE COMBINATIONS OF THE & AND const 
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
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
