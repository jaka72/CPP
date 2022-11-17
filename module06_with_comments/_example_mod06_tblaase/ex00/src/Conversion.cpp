/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 16:37:12 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/17 17:58:57 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Conversion.hpp"

// Constructors
Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
}

Conversion::Conversion(const std::string input): _input(input)
{
	std::cout << "Conversion Constructor for " << this->getInput() << std::endl;
	this->_double = atof(this->getInput().c_str());
	std::cout << "    Whatever there is, it's first saved to _double: " << _double << std::endl;
	std::cout << "            (int is now still garbage): " << _int << std::endl;
	this->convertInput();
	std::cout << "    after convertInput" << std::endl;
	this->printOutput();
}

Conversion::Conversion(const Conversion &src): _input(src.getInput())
{
	std::cout << "Conversion Copy Constructor called" << std::endl;
	*this = src;
	this->printOutput();
}

// Deconstructors
Conversion::~Conversion()
{
	std::cout << "Conversion Deconstructor called" << std::endl;
}

// Overloaded Operators
Conversion &Conversion::operator=(const Conversion &src)
{
	std::cout << "Conversion Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	return *this;
}

// Private Methods
int	Conversion::checkInput()
{
	std::cout << "Check input\n";
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
		this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0 ||
		this->getInput().compare("-inff") == 0)
	{
		std::cout << "    A) compare nan inf ... == 0" << std::endl;
		return (NAN_INF);
	}
	else if (this->getInput().length() == 1 &&
		(this->getInput()[0] == '+' || this->getInput()[0] == '-' || // prevents that the input of single digit integers get interpreted as a char
		this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
	{
		std::cout << "    C)\n";
		return (CHAR);
	}
	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-")) // catches any multiple or mixed use of + and -
	{
		std::cout << "    D)\n";
		return (ERROR);
	}
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
	{
		std::cout << "    E)\n";
		return (INT);
	}
	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		std::cout << "    F)\n";
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // catches `0..0`
			isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false || // catches `0.`
			this->getInput().find_first_of(".") == 0) // catches `.0`
			return (ERROR);
		else
		{
			std::cout << "    G)\n";
			return (DOUBLE);
		}
	}
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") || // catches `0.0ff`
			this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // catches `0..0f`
			this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 || //catches `0.f`
			this->getInput().find_first_of(".") == 0 || // catches `.0f`
			this->getInput()[this->getInput().find_first_of("f") + 1] != '\0') // catches `0.0f0`
			{
				std::cout << "    H)\n";
				return (ERROR);
			}
		else
		{
			std::cout << "    I)\n";
			//std::cout << "jaka, found float: " << getInput() << "\n"; // jaka
			std::cout << "    try casting to float: " << atof(getInput().c_str()) << "\n";

			return (FLOAT);
		}
	}
	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
		(this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
	{
		std::cout << "    J)\n";
		return (CHAR);
	}
	else
	{
		std::cout << "    K)\n";
		return (ERROR);
	}
}

void Conversion::fromChar(void)
{
	std::cout << "    called FromChar()\n";
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}
void Conversion::fromInt(void)
{
	std::cout << "    called FromInt(), storing to _int, via casting from double\n";
	std::cout << "       When was this saved to double " << getDouble() << " \n";

	// this->_int = static_cast<int>(this->getDouble());
	std::cout << "       int before " << _int << "(garbage) \n";
	this->_int = static_cast<int>(this->_double);	// seems it does the same
	std::cout << "       int after  " << _int << " (intMIN)\n";
	
	std::cout << "       char before " << (int)_char << " " << _char << " (garbage) \n";
	this->_char = static_cast<unsigned char>(this->getInt());
	std::cout << "       char after  " << (int)_char << " (...) \n";
	
	
	
	std::cout << "       float before " << _float << " (garbage) \n";
	this->_float = static_cast<float>(this->getDouble());
	std::cout << "       float after  " << _float << " (floatMIN) \n";
}
void Conversion::fromFloat(void)
{
	std::cout << "    called FromFloat()\n";
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}
void Conversion::fromDouble(void)
{
	std::cout << "    called FromDouble(), saved: " << getDouble() <<"\n";
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}




void	Conversion::convertInput(void)
{
	std::cout << "Convert Input \n";

	void (Conversion::*functionPTRS[])(void) =	// array of  pointers to functions
	{
		&Conversion::fromChar, 
		&Conversion::fromInt, 
		&Conversion::fromFloat, 
		&Conversion::fromDouble
	};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = checkInput();		// it returns the origina type from input, ie: INT
	std::cout << "   after checkInput, found type: " << _type << " (6=double)\n";

	if (this->getType() == NAN_INF)
		return ;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])	// find and call correct function according to type
		{									// each function converts and saves into all other types
			(this->*functionPTRS[i])();
			break ;
		}
	}
	std::cout << "   called function i " << i << " \n";
	if (i == 4)
		throw Conversion::ErrorException();
}




void	Conversion::printOutput(void)const
{
	// display char
	if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
	{
		if (isprint(this->getChar()))
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// display int
	if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << this->getInt() << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	// display float
	if (this->getType() != NAN_INF)
	{
		std::cout << "Display float\n";
		std::cout << "   float: " << this->getFloat();
		if (this->getFloat() - this->getInt() == 0)
		{	
			//std::cout << "       a)\n";
			std::cout << ".0f" << std::endl;
		}
		else
		{
			//std::cout << "       b)\n";
			std::cout << "f" << std::endl;
		}
	}
	else
	{
			//std::cout << "       c)\n";
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// display double
	if (this->getType() != NAN_INF)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() ||
			this->getDouble() - this->getInt() == 0)
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

// Exceptions
const char *Conversion::ErrorException::what(void) const throw()
{
	return ("Error: Impossible to print or input not convertable");
};

// Getter
std::string	Conversion::getInput(void)const
{
	return (this->_input);
}

int	Conversion::getType(void)const
{
	return (this->_type);
}

char	Conversion::getChar(void)const
{
	return (this->_char);
}

int	Conversion::getInt(void)const
{
	return (this->_int);
}

float	Conversion::getFloat(void)const
{
	return (this->_float);
}

double Conversion::getDouble(void)const
{
	return (this->_double);
}

// Setter

