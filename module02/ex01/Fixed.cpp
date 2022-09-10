#include "Fixed.hpp"
#include <cmath>

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
		
			// MAYBE IT CAN BE SIMPLER:  ???
			//	*this = f1_default;
		}

// A CONSTRUCTOR FOR INT
		Fixed::Fixed(const int i)
		{
			std::cout << "Called CONSTRACTOR WITH INT\n";
			// HOW CAN THIS INT BE CONVERTED INTO FIXED POINT ??? IF IT ALREADY IS INT ??
			fpn_prive = i;
		}

// A CONSTRUCTOR FOR FLOAT
		Fixed::Fixed(const float f)
		{
			std::cout << "Called CONSTRACTOR WITH FLOAT\n";
			fpn_prive = std::round(f * (1 << frac_bits));
	
			std::cout << fpn_prive << '\n';

		}


//	COPY ASSIGNMENT OVERLOAD
		Fixed &Fixed::operator=(const Fixed &orig)
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

// MEMBER FUNCTIONS
		float Fixed::toFloat(void) const
		{
			float a;
			a = fpn_prive / (float)(1 << frac_bits); // MUST BE CASTED TO FLOAT !!!
			std::cout << " .... called toFloat: a=" << a << " ...\n";
			return (a);
		}
		
		float Fixed::toInt(void) const
		{
			int a;
			a = fpn_prive / (1 << frac_bits);
			//std::cout << " .... called toInt: a=" << a << '\n';
			return (a);
		}
// OVERLOAD FOR THE << OPERATOR, for printing and converting the fpn value
//		from the object. 
// std::ostream &operator<<(std::ostream &out,     Fixed &f)
std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}