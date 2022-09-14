#include "Fixed.hpp"
#include <cmath>

// const int Fixed::frac_bits = 8;	// why would this be better then 
									// inside class definition ???


// DEFAULT CONSTRUCTOR
Fixed::Fixed()	:	m_fpn {0}
{
	std::cout << "Default constructor called\n"; 
	// m_fpn = 0;
}


// COPY CONSTRUCTOR
/* 
	IT MAKES ANOTHER INSTANCE OF THE SAME CLASS
		Fixed a();
		Fixed b(a);
	CAN GET THE VALUES FROM THE DEFAULT CONSTRUCTOR,
	OR IT CAN GET ITS OWN VALUES
*/
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n"; 
	// m_fpn = fixed.m_fpn;	// Copy the value from the default constructor
	//	OR
	*this = fixed; // This requires the Copy Assign. overload for =
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	//std::cout << "      xxx" << m_fpn << "\n";
	m_fpn = i << frac_bits; // same as i * 256
	//std::cout << "      XXX" << m_fpn << "\n";
	// OR
	// m_fpn = std::round(i * (1 << frac_bits));
	// std::cout << "   fpn=" << m_fpn << "\n";
}


// A CONSTRUCTOR FOR ARG. FLOAT
// Bit shifting can not be used on floats, so it has to be multiplied
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	m_fpn = std::round(f * (1 << frac_bits));	
	std::cout << "      current fpn: " << m_fpn << '\n';
}



// COMPARISSON
// variation A)
bool	Fixed::operator== (const Fixed &fixed) const
{
	//std::cout << "From operator== " << this->m_fpn / 256 << "\n";
	return (this->m_fpn == fixed.m_fpn);
}

// variation B)
// NOT POSSIBLE
//	TO HAVE 2 ARGS IS MAYBE ONLY POSSIBLE WITH A FRIEND ????
// bool	Fixed::operator== (const Fixed &f1, const Fixed &f2)
// {
// 	return (f1.m_fpn == f2.m_fpn);
// }

bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (this->m_fpn != fixed.m_fpn);
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
	return (this->m_fpn < fixed.m_fpn);
}

bool	Fixed::operator> (const Fixed &fixed) const
{
	return (this->m_fpn > fixed.m_fpn);
}

bool	Fixed::operator<= (const Fixed &fixed) const
{
	return (this->m_fpn <= fixed.m_fpn);
}

bool	Fixed::operator>= (const Fixed &fixed) const
{
	return (this->m_fpn >= fixed.m_fpn);
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
	++this->m_fpn;
	return (*this);
}

Fixed Fixed::operator-- ()
{
	--this->m_fpn;
	return (*this);
}

Fixed Fixed::operator++ (int)		// POST-INCREMENT
{
	Fixed temp {*this};
	//std::cout << "this: " << this->m_fpn << ".  tmp: " << tmp.m_fpn << '\n';
	++this->m_fpn;
	//std::cout << "this: " << this->m_fpn << ".  tmp: " << tmp.m_fpn << '\n';
	return (temp);
}

Fixed Fixed::operator-- (int)		// POST-INCREMENT
{
	Fixed temp = *this;
	--this->m_fpn;
	return (temp);
}


// ARITHMETIC OPERATORS //////////////////////////////
/*
	Could also be without the temp:
		this->m_fpn = m_fpn + fixed.m_fpn;
		return *this;
*/
Fixed Fixed::operator+ (const Fixed &fixed)
{
	Fixed temp;
	temp.m_fpn = m_fpn + fixed.m_fpn;
	return temp;
}

Fixed Fixed::operator- (const Fixed &fixed)
{
	Fixed temp;
	temp.m_fpn = m_fpn - fixed.m_fpn;
	return temp;
}

/*
	!!! IT HAS TO BE SHIFTED BACK TO >> frac_bits  ( / 256), BECAUSE 
	IT WAS SHIFTED << frac_bits ( * 256) IN THE CONASTRUCTOR(int) 
*/
Fixed Fixed::operator* (const Fixed &fixed)
{
	Fixed temp;
	temp.m_fpn = (m_fpn * fixed.m_fpn) >> frac_bits;
	return temp;
}

/*
	BOTH FLOAT VALUES BECAME INTS IN THE CONSTRUCTOR (via shifting * 256 ). 
	SO NOW THEY MUST BE CAST BACK TO FLOAT, TO BE CORRECTLY DIVIDED. 
	THE RESULT MUST BE AGAIN SHIFTED ( * 256) TO INT, BECAUSE FINALY IT
	WILL BE PRINTED VIA toFloat() --> SHIFTED BACK TO FLOAT  
*/
Fixed Fixed::operator/ (const Fixed &fixed)
{
	Fixed temp;
	float temp_float;

	if (fixed.m_fpn == 0)  // protection for zero division
	{
		std::cout << "Cannot divide by zero.\n";
		return *this;
	}
	// std::cout << "   this.fpn: " << (this->m_fpn / 256) << "\n"; 
	// std::cout << "   fixed.fpn: " << (fixed.m_fpn / 256) << "\n"; 

	temp_float = (float)this->m_fpn / (float)fixed.m_fpn;
	temp.m_fpn = (int)(temp_float * (1 << frac_bits));
	return temp;
}

////////////////////////////////////////////////////////////////////////////////////
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
Fixed &Fixed::operator= (const Fixed &orig)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
	this->m_fpn = orig.m_fpn;
		// IS THIS THE SAME?  WHY WOULD YOU HERE USE getRawBits()  ???
		// 		this->m_fpn = orig.getrawBits();
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
	m_fpn = raw << frac_bits;
	std::cout << "setRawBits member function called: new value fpn: " << m_fpn <<"\n"; 
	//Fixed::m_fpn = raw;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called: value: \n" << m_fpn <<"\n"; 
	return m_fpn;
}


// PUBLIC MEMBER FUNCTIONS
float Fixed::toFloat(void) const
{
	float a;
	//std::cout << " .... called toFloat: fpn=" << m_fpn << " ...\n";
	a = m_fpn / (float)(1 << frac_bits); // MUST BE CASTED TO FLOAT !!!
	return (a);
}
		
float Fixed::toInt(void) const
{
	//std::cout << " .... called toInt: fpn=" << m_fpn << '\n';
	int a;
	a = m_fpn >> this->frac_bits;
	// ALSO POSSIBLE:
	// a = m_fpn / (1 << frac_bits);
	return (a);
}

/*
	If one or both args are const, then the Const-version of min() is called.
	If both args are not const, then the Non-const version of min() is called.
*/
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	std::cout << "Called MIN NO CONST\n";
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

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	std::cout << "Called MIN with CONST\n";
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

// OVERLOAD FOR THE << STREAM OPERATOR
/*
	It is for printing and converting the fpn value from the object.
	The return type is ostream.
	The function name operator<< must have the &	?????
	WHAT IS THE LOGIC WITH THESE &  ???
	DOES THIS ONE ALSO HAVE ->this	???
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
