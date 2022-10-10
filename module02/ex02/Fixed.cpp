/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:47:06 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:32:06 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
Fixed::Fixed()	:	_fpn(0)
{	}


// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed; // This requires the Copy Assign. overload for =
}


// A CONSTRUCTOR FOR ARG. INT
Fixed::Fixed(const int i)
{
	_fpn = i << _frac_bits; // same as i * 256
}


// A CONSTRUCTOR FOR ARG. FLOAT
Fixed::Fixed(const float f)
{
	_fpn = roundf(f * (1 << _frac_bits));	
}


// DESTRUCTOR
Fixed::~Fixed()
{	}


// COPY ASSIGNMENT =OPERATOR OVERLOAD /////////////////////////////
Fixed &Fixed::operator= (const Fixed &orig)
{
	if (this == &orig)	// Protection
		return (*this);
	this->_fpn = orig._fpn;
	return (*this);
}


// OVERLOAD FOR OSTREAM OPERATOR<<
std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


// PUBLIC MEMBER FUNCTIONS /////////////////////////////////////////////////

//	SETTER
void Fixed::setRawBits(int const raw)
{
	_fpn = raw << _frac_bits;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	return _fpn;
}


float Fixed::toFloat(void) const
{
	float a;
	a = _fpn / (float)(1 << _frac_bits); // MUST BE CASTED TO FLOAT !!!
	return (a);
}
		
float Fixed::toInt(void) const
{
	int a;
	a = _fpn >> this->_frac_bits;	// 	OR  a = _fpn / (1 << _frac_bits);
	return (a);
}


// COMPARISSON OPERATORS OVERLOAD ////////////////////////////////////////////
bool	Fixed::operator== (const Fixed &fixed) const
{
	return (this->_fpn == fixed._fpn);
}


bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (this->_fpn != fixed._fpn);
}


bool	Fixed::operator< (const Fixed fixed) const
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


// ARITHMETIC OPERATORS //////////////////////////////
Fixed Fixed::operator+ (const Fixed &fixed)
{
	// Fixed temp;
	// temp._fpn = _fpn + fixed._fpn;
	// return temp;
	this->_fpn = _fpn + fixed._fpn;
	return *this;
}

Fixed Fixed::operator- (const Fixed &fixed)
{
	this->_fpn = _fpn - fixed._fpn;
	return *this;
}

// To multiply correctly, it needs to be shifted back to 
// original value with  >> 8 bits
Fixed Fixed::operator* (const Fixed &fixed)
{
	Fixed temp;
	temp._fpn = (_fpn * fixed._fpn) >> _frac_bits;	/// ?????? WHY EXACTLY?
	return temp;
}


//	Both float values became ints in the constructor (via shifting << 8)
//	So now they must be cast back to float, to be correctly divided.
//	The result must be again shifted << 8 to int, because finaly it
//	will be printed via toFloat() --> shifted back to float
Fixed Fixed::operator/ (const Fixed &fixed)
{
	float temp_float;

	if (fixed._fpn == 0)  // protection from zero division
	{
		std::cout << "Cannot divide by zero.\n";
		return *this;
	}
	temp_float = (float)this->_fpn / (float)fixed._fpn;
	this->_fpn = (int)(temp_float * (1 << _frac_bits));
	return *this;
}




// INCREMENT OPERATORS /////////////////////////////////////////////////

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
	} */

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
	++this->_fpn;
	return (temp);
}

Fixed Fixed::operator-- (int)
{
	Fixed temp = *this;
	--this->_fpn;
	return (temp);
}



//	If one or both args are const, then the Const-version of min() is called.
//	If both args are not const, then the Non-const version of min() is called.
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	std::cout << "     Called min() without const: ";
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	std::cout << "     Called max() without const: ";
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	std::cout << "     Called min()    with const: ";
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	std::cout << "     Called max()    with const: ";
	if (f1 > f2)
		return (f1);
	return (f2);
}
