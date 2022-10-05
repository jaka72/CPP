/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/01 11:17:32 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
		Fixed::Fixed()
		{
			std::cout << "Default constructor called\n"; 
			_fixedPointNumber = 0;
		}


// COPY CONSTRUCTOR (must also be outside of class !!)
		/* CAN GET THE VALUES FROM THE DEFAULT CONSTRUCTOR,
		OR IT CAN GET ITS OWN VALUES  */
		Fixed::Fixed(const Fixed &f1_default)
		{
			std::cout << "Copy constructor called\n"; 
			_fixedPointNumber = f1_default._fixedPointNumber;	// from the default
			_fixedPointNumber = 44;						// Its own new value
		}


//	COPY ASSIGNMENT OVERLOAD
		Fixed &Fixed::operator= (const Fixed &orig)
		{
			std::cout << "Copy assignment operator called\n";
			// Protection
			if (this == &orig)
				return (*this);
			this->_fixedPointNumber = orig._fixedPointNumber;
				// IS THIS THE SAME?
				// 		this->_fixedPointNumber = orig.getrawBits();
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
			//Fixed::_fixedPointNumber = raw;
		}


//	GETTER
		int Fixed::getRawBits(void) const
		{
			std::cout << "getRawBits member function called\n"; 
			return _fixedPointNumber;
		}