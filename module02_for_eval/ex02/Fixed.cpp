/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:47:06 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/05 20:05:32 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// const int Fixed::_frac_bits = 8;	// why would this be better then 
									// inside class definition ???


// DEFAULT CONSTRUCTOR
Fixed::Fixed()	:	_fpn (0)
{
	// std::cout << "Default constructor called\n"; 
	// _fpn = 0;
}


// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called\n"; 
	// _fpn = fixed._fpn;	// Copy the value from the default constructor
	//		OR
	*this = fixed; // This requires the Copy Assign. overload for =
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	//std::cout << "Int constructor called\n";
	_fpn = i << _frac_bits; // same as i * 256
	// 		OR
	// _fpn = std::round(i * (1 << _frac_bits));
}


// A CONSTRUCTOR FOR ARG. FLOAT
// Bit shifting can not be used on floats, so it has to be multiplied
Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called\n";
	_fpn = round(f * (1 << _frac_bits));	
	//std::cout << "      current fpn: " << _fpn << '\n';
}



// COMPARISSON
// variation A)
bool	Fixed::operator== (const Fixed &fixed) const
{
	//std::cout << "From operator== " << this->_fpn / 256 << "\n";
	return (this->_fpn == fixed._fpn);
}

// variation B)
// NOT POSSIBLE
//	TO HAVE 2 ARGS IS MAYBE ONLY POSSIBLE WITH A FRIEND ????
// bool	Fixed::operator== (const Fixed &f1, const Fixed &f2)
// {
// 		return (f1._fpn == f2._fpn);
// }

bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (this->_fpn != fixed._fpn);
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
bool	Fixed::operator< (const Fixed fixed) const
// bool	Fixed::operator< (Fixed fixed) const
{
	return (this->_fpn < fixed._fpn);
}

bool	Fixed::operator> (const Fixed &fixed) const
{
	return (this->_fpn > fixed._fpn);
}

bool	Fixed::operator<= (const Fixed &fixed) const
{
	return (this->_fpn <= fixed._fpn);
}

bool	Fixed::operator>= (const Fixed &fixed) const
{
	return (this->_fpn >= fixed._fpn);
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
	++this->_fpn;
	return (*this);
}

Fixed Fixed::operator-- ()
{
	--this->_fpn;
	return (*this);
}

Fixed Fixed::operator++ (int)		// POST-INCREMENT
{
	Fixed temp (*this);
	//std::cout << "this: " << this->_fpn << ".  tmp: " << tmp._fpn << '\n';
	++this->_fpn;
	//std::cout << "this: " << this->_fpn << ".  tmp: " << tmp._fpn << '\n';
	return (temp);
}

Fixed Fixed::operator-- (int)		// POST-INCREMENT
{
	Fixed temp = *this;
	--this->_fpn;
	return (temp);
}


// ARITHMETIC OPERATORS //////////////////////////////
/*
	Could also be without the temp:
		this->_fpn = _fpn + fixed._fpn;
		return *this;
*/
Fixed Fixed::operator+ (const Fixed &fixed)
{
	Fixed temp;
	temp._fpn = _fpn + fixed._fpn;
	return temp;
}

Fixed Fixed::operator- (const Fixed &fixed)
{
	Fixed temp;
	temp._fpn = _fpn - fixed._fpn;
	return temp;
}

/*
	!!! IT HAS TO BE SHIFTED BACK TO >> _frac_bits  ( / 256), BECAUSE 
	IT WAS SHIFTED << _frac_bits ( * 256) IN THE CONSTRUCTOR(int) 
*/
Fixed Fixed::operator* (const Fixed &fixed)
{
	Fixed temp;
	temp._fpn = (_fpn * fixed._fpn) >> _frac_bits;
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

	if (fixed._fpn == 0)  // protection for zero division
	{
		std::cout << "Cannot divide by zero.\n";
		return *this;
	}
	// std::cout << "   this.fpn: " << (this->_fpn / 256) << "\n"; 
	// std::cout << "   fixed.fpn: " << (fixed._fpn / 256) << "\n"; 

	temp_float = (float)this->_fpn / (float)fixed._fpn;
	temp._fpn = (int)(temp_float * (1 << _frac_bits));
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
	//std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
	this->_fpn = orig._fpn;
		// IS THIS THE SAME?  WHY WOULD YOU HERE USE getRawBits()  ???
		// 		this->_fpn = orig.getrawBits();
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
	_fpn = raw << _frac_bits;
	std::cout << "setRawBits member function called: new value fpn: " << _fpn <<"\n"; 
	//Fixed::_fpn = raw;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called: value: \n" << _fpn <<"\n"; 
	return _fpn;
}


// PUBLIC MEMBER FUNCTIONS
float Fixed::toFloat(void) const
{
	float a;
	//std::cout << " .... called toFloat: fpn=" << _fpn << " ...\n";
	a = _fpn / (float)(1 << _frac_bits); // MUST BE CASTED TO FLOAT !!!
	return (a);
}
		
float Fixed::toInt(void) const
{
	//std::cout << " .... called toInt: fpn=" << _fpn << '\n';
	int a;
	a = _fpn >> this->_frac_bits;
	// ALSO POSSIBLE:
	// a = _fpn / (1 << _frac_bits);
	return (a);
}

/*
	If one or both args are const, then the Const-version of min() is called.
	If both args are not const, then the Non-const version of min() is called.
*/
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	std::cout << "Called min() without const\n";
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	std::cout << "Called max() without const \n";
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	std::cout << "Called min() with const \n";
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	std::cout << "Called max() with const \n";
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
