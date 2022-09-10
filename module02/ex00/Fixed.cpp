#include "Fixed.hpp"

// DEFAULT CONSTRUCTOR
		Fixed::Fixed()
		{
			std::cout << "Default constructor called\n"; 
			fpn_prive = 0;
		}


// COPY CONSTRUCTOR (must also be outside of class !!)
		/* CAN GET THE VALUES FROM THE DEFAULT CONSTRUCTOR,
		OR IT CAN GET ITS OWN VALUES  */
		Fixed::Fixed(const Fixed &f1_default)
		{
			std::cout << "Copy constructor called\n"; 
			fpn_prive = f1_default.fpn_prive;	// from the default
			// fpn_prive = 44;						// Its own new value
		}


//	COPY ASSIGNMENT OVERLOAD
		Fixed &Fixed::operator= (const Fixed &orig)
		{
			std::cout << "Copy assignment operator called\n";
			// Protection
			if (this == &orig)
				return (*this);
			this->fpn_prive = orig.fpn_prive;
				// IS THIS THE SAME?
				// 		this->fpn_prive = orig.getrawBits();
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
			fpn_prive = raw;
			//Fixed::fpn_prive = raw;
		}


//	GETTER
		int Fixed::getRawBits(void) const
		{
			std::cout << "getRawBits member function called\n"; 
			return fpn_prive;
		}
