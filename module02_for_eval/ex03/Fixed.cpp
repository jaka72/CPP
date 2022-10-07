/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 13:55:40 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 13:58:37 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


// DEFAULT CONSTRUCTOR
Fixed::Fixed()
{
	//std::cout << "Default constructor called\n"; 
	_fpn = 0;
}


// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called\n"; 
	//_fpn = fixed._fpn;	// from the default
	*this = fixed;
}

//	COPY ASSIGNMENT OVERLOAD FOR =OPERATOR
Fixed &Fixed::operator=(const Fixed &orig)
{
	//std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
	this->_fpn = orig._fpn;
	return (*this);
}


// PARAMETERIZED CONSTRUCTORS
Fixed::Fixed(const int i)
{
	//std::cout << "Int constructor called\n";
	_fpn = i << _frac_bits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called\n";
	_fpn = round(f * (1 << _frac_bits));	
	//std::cout << "Converted from float " << f << " to fixed point: " << _fpn << "\n\n";
}


// DESTRUCTOR
Fixed::~Fixed()
{
	// std::cout << "Destructor FIXED\n";
}


// PUBLIC MEMBER FUNCTIONS

//	SETTER
void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n"; 
	_fpn = raw;
}

//	GETTER
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n"; 
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
	a = _fpn >> this->_frac_bits;
	// 	OR
	// a = _fpn / (1 << _frac_bits);
	return (a);
}


// OVERLOAD FOR THE << OPERATOR
std::ostream &operator<< (std::ostream &out, Fixed const &f)
{
	 out << f.toFloat();
	return (out);
}
