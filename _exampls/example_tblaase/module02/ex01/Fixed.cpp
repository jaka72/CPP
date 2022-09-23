
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

// Constructors
Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Fixed Int Constructor called" << std::endl;
	//std::cout << "     fp_value: " << _fp_value << "\n";
	//std::cout << "     input: " << input << "\n";
	this->_fp_value = input << this->_fract_bits;
	//std::cout << "     fp_value: " << _fp_value << "\n";


	// int c {11 << 8};
	// std::cout << "     test c<<    :" << c << "\n";

}

Fixed::Fixed(const float input)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	//std::cout << "     fp_value: " << _fp_value << "\n";	// jaka
	//std::cout << "     input: " << input << "\n";			// jaka
	
	// HERE IT BITSHIFTS NR 1 << FOR 8 BITS, WHICH IS ALWAYS:
	//						1 << 8 == 100000000 == 256
	//	THEN MULTIPLIES IT WITH THE CURRENT INPUT     input
	//										== 256  *  0.5   = 128
	//	THEN IT ROUNDS THE NEW VALUE, SO IT BECOMES AN INTEGER
	this->_fp_value = roundf(input * (1 << this->_fract_bits));

	//std::cout << "     fp_value: " << _fp_value << "\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = copy;
}

// Deconstructors
Fixed::~Fixed()
{
	std::cout << "Fixed Deconstructor called" << std::endl;
}

// Overloaded Operators
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_fp_value = src.getRawBits();
		// _fp_value = src.getRawBits();
		//_fp_value = src._fp_value;
		// OR ???
		//this = src;  // NO, IT CAN'T BE LIKE IN CONSTRUCTOR
	}


	return *this;
}



// Public Methods
float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}



// Getter
int	Fixed::getRawBits(void)const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

// Setter
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}


std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	//std::cout << "CALLED OVERLOAD << \n";
	o << fixed.toFloat();
	return (o);
}