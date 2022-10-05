/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/05 18:18:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
Fixed::Fixed()
{
	std::cout << "Default constructor called\n"; 
	_fixedPointNumber = 0;
}


// COPY CONSTRUCTOR
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n"; 
	*this = copy;

}


//	COPY ASSIGNMENT OVERLOAD
Fixed& Fixed::operator= (const Fixed& orig)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &orig)	// Protection
		return (*this);
		
	this->_fixedPointNumber = orig._fixedPointNumber; // OR
//	this->_fixedPointNumber = orig.getRawBits();
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
	_fixedPointNumber = raw;
}


//	GETTER
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n"; 
	return _fixedPointNumber;
}
