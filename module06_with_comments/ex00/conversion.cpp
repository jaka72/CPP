/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/02 20:14:32 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

// Constructor
Conversion::Conversion() 
{
	std::cout << GRE"Default constr (Conversion) " << "\n" RES;
}


// Param. constr.
Conversion::Conversion(std::string str) : _inputStr(str)
{
	std::cout << GRE"Param. constructor (Conversion) inputStr: [" << _inputStr << "]\n" RES;
	_i          = 0;
	_c			= 'x';
    _intg		= 0 ;

	_isDigit = 0;
	_isNotDigit = 0;
	_isPoint = 0;
	_isSpace = 0;
	_isF = 0;
	_sign = 0;
	_isNeg = 0;
	_checkIf_F = 'a';

	_int_overflow = 0;
	_float_overflow = 0;
	_double_overflow = 0;

	processInputStr();
	storeCorrectType();
	convert();
	print_all();

	// try
	// { ;	}
	// catch(const std::exception& e)
	// { std::cerr << e.what() << '\n'; }
}



// Copy constructor
Conversion::Conversion(const Conversion &src)
{
	std::cout << GRE"Copy constructor:   " << "\n" RES;
	*this = src;
}



// Overload operators
Conversion& Conversion::operator= (const Conversion &src)
{
	std::cout << GRE"Overload operator=  (Conversion)" << "\n" RES;

	// try
	// {	}
	// catch(const std::exception& e)
	// { 		std::cerr << e.what() << '\n';	}
	
	this->_inputStr = src._inputStr;
	return *this;
}

// Destructor
Conversion::~Conversion()
{
	std::cout << GRE"Destructor (Conversion) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions


int	Conversion::convert()
{
		// std::cout << " ---------------------- intg " << _intg << "\n";
	if (_type == CHAR)
	{
		_intg	= (int)_c;
		_f		= (float)_c;
		_d		= (double)_c;
	}
	else if (_type == INT)
	{
		_c = (int)_intg;
		_f = (float)_intg;
		_d = (double)_intg;
	}
	else if (_type == FLOAT)
	{
		_c 		= (char)_f;
		_intg 	= (int)_f;
		_d 		= (double)_f;
	}
	else if (_type == DOUBLE)
	{
		_c 		= (char)_d;
		_intg 	= (int)_d;
		_f 		= (double)_d;
	}
	return (0);
}


void	Conversion::print_char()
{
	if ((_intg >= 0 && _intg <= 31) || (_intg >= 127 && _intg <= 255))
		std::cout << "char:  'non-printable'\n";
	else if (_intg < 0 || _intg > 255)
		std::cout << "char:  'not-possible'\n";
	else
		std::cout << "char:  '" << _c 		<< "'\n";
}



void	Conversion::print_all()
{
	std::cout << "Print all()      _c [" << _c << "] \n";

	// print char
	if (_type == CHAR && isprint(_c))
	{
		std::cout << "char:  '" << _c 		<< "'\n";
		std::cout << "int:    " << _intg	<<  "\n";
		std::cout << "float:  " << _f 		<<  ".0f\n";
		std::cout << "double: " << _d 		<<  ".0\n";
	}
	if (_type == INT)
	{
		print_char();
		std::cout << "int:    " << _intg	<<  "\n";		
		std::cout << "float:  " << _f 		<<  ".0f\n";
		std::cout << "double: " << _d 		<<  ".0\n";
	}
	if (_type == FLOAT)
	{
		print_char();
		std::cout << "int:    " << _intg	<<  "\n";
		
		if (_f - (int)_f == 0)
		{
			std::cout << "FLOAT, no decimals\n";
			std::cout << "float:  " << _f 		<<  ".0f\n";
			std::cout << "double: " << _d 		<<  ".0\n";
		}
		else
		{
			std::cout << "float:  " << _f 		<<  "f\n";
			std::cout << "double: " << _d 		<<  "\n";
		}
	}
	if (_type == DOUBLE)
	{
		print_char();
		std::cout << "int:    " << _intg	<<  "\n";

		if (_d - (int)_d == 0)
		{
			std::cout << "FLOAT, no decimals\n";
			std::cout << "float:  " << _f 		<<  ".0f\n";
			std::cout << "double: " << _d 		<<  ".0\n";
		}
		else
		{
			std::cout << "float:  " << _f 		<<  "f\n";
			std::cout << "double: " << _d 		<<  "\n";
		}
	}
	if (_type == INVALID_INPUT)	// this is not ok here, it should probably go to 
	{							// the convert section, and there check overflow for each type

		if (_int_overflow == 1)
		{
			std::cout << "char:  'not-possible'\n";
			std::cout << "int:   'not-possible'\n";
		}
	}
}

//IT NEEDS TO DETECT A SINGLE SPACE AND SINGLE DOT !!!

std::string trimWhiteSpaces(std::string str)
{
    const char* whiteSpaces = " \n\r\t\f\v";
	
    str.erase(0, str.find_first_not_of(whiteSpaces));	// at start
    str.erase(str.find_last_not_of(whiteSpaces) + 1);			// at end
    return str;
}



int	Conversion::processInputStr()
{

	std::cout << "PIS [" << _inputStr << "]\n";

	// Check immediately for ' '
	if (strlen(_inputStr.c_str()) == 1 && _inputStr[0] == ' ')
	{
		_c = _inputStr[0];
		_isNotDigit++;
		std::cout << "         SINGLE SPACE:  _c [" << _c << "] \n";
		_type = CHAR;
		return (CHAR);
	}

	// Check for multiple spaces
	if (strlen(_inputStr.c_str()) > 1)
	{
		size_t i = 0;
		while (_inputStr[i])
		{
			if (!isspace(_inputStr[i]))
				break ;
			i++;
		}
		if (i == strlen(_inputStr.c_str()))
		{
			std::cout << "         ONLY SPACES IN THE STR [" << _inputStr << "] \n";
			_type = INVALID_INPUT;
			return (INVALID_INPUT);
		}
	}

	// Trim spaces at start and end
	std::cout << "SCT before trim [" << _inputStr << "]\n";
	_inputStr = trimWhiteSpaces(_inputStr);
	std::cout << "SCT after trim  [" << _inputStr << "]\n";

	while (isspace(_inputStr[_i])) // skip spaces on start
	{
		//std::cout << "check space " << (int)_inputStr[_i] << "[" << _inputStr[_i] << "]\n";
		_c = _inputStr[_i];
		_isSpace++;
		_i++;
	}
	
	//std::cout << "B) First after space " << _i << ",  " << (int)_inputStr[_i] <<"[" << _inputStr[_i] << "]\n";

	if (_inputStr[_i] == '.')
		_c = '.';
		
	if (_inputStr[_i] == '+' || _inputStr[_i] == '-')
	{
		_sign = 1;
		_c = _inputStr[_i];
		if (_inputStr[_i] == '-')
			_isNeg = 1;
		//std::cout << "  YES IS SIGN " << _inputStr[_i] << "\n";
		_i++;
		//std::cout << "check char " << (int)_inputStr[_i] << "[" << _inputStr[_i] << "]\n";
		while (isspace(_inputStr[_i])) // skip spaces after sign
		{
			//std::cout << "First after sign and spaces " << (int)_inputStr[_i] << "[" << _inputStr[_i] << "]\n";
			_i++;
		}
	}

	//std::cout << " First after sign and spaces " << (int)_inputStr[_i] << "[" << _inputStr[_i] << "]\n";


	_start = _i;
		
	while (_inputStr[_i])
	{
		if (isdigit(_inputStr[_i]) == 0 && _inputStr[_i] != '.' && _inputStr[_i] != 'f' && _inputStr[_i] != ' ')
		{
			_isNotDigit++;
			_c = _inputStr[_i];
			//std::cout << "nondigit " << (int)_inputStr[_i] << "\n";
		}
		if (isdigit(_inputStr[_i]))
			_isDigit++;
		if (_inputStr[_i] == '.')
			_isPoint++;
		if (_inputStr[_i] == 'f')
		{
			_isF++;
			if (_inputStr[_i + 1] == '\0' || _inputStr[_i + 1] == ' ')
			{
				_checkIf_F = _inputStr[_i];
				//std::cout << " !!! found space OR end!, last char [" << _inputStr[_i] << "]\n";
				//break ;
			}    
		}
		// if (isspace(str[i]))
		if (_inputStr[_i] == ' ')
		{
			_checkIf_F = _inputStr[_i - 1];
			//std::cout << " !!! found space before end!, last char [" << _inputStr[_i - 1] << "]\n";
			break ;
		}
		_i++;
	}
	
	while (_inputStr[_i]) // check the rest of space after 1st group of chars
	{
		if (isprint(_inputStr[_i]) && _inputStr[_i] != ' ')
		{
			std::cout << _inputStr[_i] << " !!! Error, invalid input: found more chars after space!\n";
			return 1;
			// break ;
		}
		_i++;
	}
	return 0;
}

/////////////////////////////////////////////////////




void printStats(int isDigit, int isNotDigit, int isPoint, int isF, int sign, int isNeg, int isSpace)
{
    std::cout << "      digits:     " << isDigit << "\n";
    std::cout << "      non-digits: " << isNotDigit << "\n";
    std::cout << "      points:     " << isPoint << "\n";
    std::cout << "      fs:         " << isF << "\n";
    std::cout << "      sign:       " << sign << "\n";
    std::cout << "      isNeg:      " << isNeg << "\n";
    std::cout << "      isSpace:    " << isSpace << "\n";
}




int	Conversion::storeCorrectType()
{
	//std::cout << "   all together: " << isNotDigit + isPoint + isF + isDigit << "\n";

	// std::cout << "SCT before trim [" << _inputStr << "]\n";
	// _inputStr = trimWhiteSpaces(_inputStr);
	// std::cout << "SCT after trim  [" << _inputStr << "]\n";
	

	if (_type == INVALID_INPUT)
		return (INVALID_INPUT);

	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit == 0))
	{
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg, _isSpace);
		std::cout << "SINGLE CHAR THE SIGN FOUND\n";
		std::cout << "Must be CHAR, str [" << _inputStr << "],  c [" << _c << "]\n"; 
		std::cout << "Result: " << _c << "\n";
		_type = CHAR;
		return (CHAR);
	}
	
	
	printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg, _isSpace);
	if (_sign == 0 && (_isNotDigit + _isPoint + _isF + _isDigit + _isSpace) == 1)
	{
		std::cout << "SINGLE CHAR \n";
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg, _isSpace);

		// if (_isSpace == 1)
		// 	_c = ' ';
		if (_isNotDigit == 1 || _isPoint == 1 || _isSpace == 1)
		{
			std::cout << "Must be CHAR, str [" << _inputStr << "],  c [" << (int)_c << _c << "]\n"; 
			std::cout << "Result: " << _c << "\n";
			_type = CHAR;
			return (CHAR);
		}
		// HERE PROBABLY NEEDS TO BE _intg INSTEAD OF _i  ???????????????????
		if (_isDigit == 1)
		{
			std::cout << "Must be SINGLE INT, str [" << _inputStr << "],  c [" << _i << "]\n";
			std::cout << "Must be SINGLE INT, str [" << _inputStr << "],  c [" << _inputStr[_start] << "]\n";
			_intg = (int)(_inputStr[_start] - 48);
			std::cout << "Result: " << _intg << "\n";
			_type = INT;
			return (INT);
		}
	}
	// HERE PROBABLY NEEDS TO BE _intg INSTEAD OF _i  ???????????????????
	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit) == 1)
	{
		if (_isDigit == 1)
		{
			std::cout << "Must be SINGLE INT WITH SIGN, str [" << _inputStr << "],  c [" << _inputStr[_start] << "]\n";
			_intg = (int)(_inputStr[_start] - 48);
			if (_isNeg == 1)
				_intg *= -1;
		
			std::cout << "Result: " << _i << "\n";
			// return (11);
			_type = INT;
			return (INT);
		}
		else
		{
			std::cout << "Error: INVALID INPUT: _sign and alpha" << _i << "\n";
		}
			
	}
	// check if all good
	else if (_isPoint == 0 && _isNotDigit == 0 && _isF == 0)
	{
		std::cout << "Must be integer: " << _inputStr << "\n";
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg, _isSpace);

		// choose the correct limit
		// int limit;
		// if (_isNeg == 0)
		// 	limit = std::numeric_limits<int>::max();
		// else
		// 	limit = std::numeric_limits<int>::min();

		// if (check_overflow(&str[start], std::numeric_limits<int>::max() ) != 0)
		// if (check_overflow(&_inputStr[_start], limit) != 0)
		// {
		// 	std::cout << "Int overflow!\n";
		// 	return (1);
		// }
		
		std::cout << "      ---  _start   	       [" <<  _start 			<< "]\n";
		std::cout << "      ---  _inputStr	       [" <<  _inputStr 		<< "]\n";
		std::cout << "      ---  _inputStr[_start] [" <<  _inputStr[_start] << "]\n";
		std::cout << "      --- &_inputStr[_start] [" << &_inputStr[_start] << "]\n";

		// check_overflow via long double
		long double temp = atof(&_inputStr[_start]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			std::cout << "   INT OVERFLOW \n";
			_int_overflow = 1;;
			return (INVALID_INPUT);		
		}
		
		_intg = atoi(&_inputStr[_start]);
		// _intg = atoi(_inputStr.c_str());
		if (_isNeg == 1)
			_intg *= -1;
		
		std::cout << "Result: " << _intg << "\n";
		std::cout << "        integer: " << _intg << " limit = not in use\n";
		_type = INT;
		return (INT);
	}

	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 0 && _isDigit >= 1)
	{
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg, _isSpace);
		std::cout << "Must be double: " << _inputStr << "\n";
		_d = atof(&_inputStr[_start]); // ??????
		if (_isNeg == 1)
			_d *= -1;
		std::cout << "Result: " << _d << "\n";
		_type = DOUBLE;
		return (DOUBLE);
	}
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 1 && _checkIf_F == 'f')
	{
		std::cout << "Must be float: " << _inputStr << "\n";
		_f = atof(&_inputStr[_start]);
		if (_isNeg == 1)
			_f *= -1;
		std::cout << "Result: " << _f << "\n";
		_type = FLOAT;
		return (FLOAT);
	}
	else
	{
		std::cout << "Found alphabet  [" << _inputStr << "]\n";
		std::cout << "Found alphabet  [" << _inputStr[_start] << "]\n";
		std::cout << "Found alphabet  [" << &_inputStr[_start] << "]\n";
		//_inputStr = &_inputStr[_start];
	
		_inputStr = trimWhiteSpaces(_inputStr); // maybe not needed anymore
		std::cout << "        after trim [" << _inputStr << "]  len: " <<  strlen(_inputStr.c_str()) <<  " \n";


		if (strlen(_inputStr.c_str()) == 1 /*&& isprint(_inputStr[0]) */)
		{
			std::cout << "         FOUND CHAR\n";
			_c = _inputStr[0];
			std::cout << "                _c [" << _c << "] \n";
			_type = CHAR;
			return (CHAR);
		}
		if (_inputStr == "nan" || _inputStr == "nanf")
		{
			std::cout << "Found string 'nan' [" << _inputStr << "]\n";
			return (0);
		}
		else if (_sign == 1 && (_inputStr == "inf" || _inputStr == "inff"))
		{
			std::cout << "Found string 'inf' [" << _inputStr << "]\n";
			return (0);
		}
		else
			std::cout << "Error: Invalid input, last char is not f and not digit!\n";
		return (1);
	}    
    return 0;
}
