/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 15:00:41 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// Constructor
Conversion::Conversion() 
{
	//std::cout << GRE"Default constr (Conversion) " << "\n" RES;
}


// Param. constr.
Conversion::Conversion(std::string str) : _inputStr(str)
{

	_i          	= 0;
	_c				= 'x';
	_intg			= 0;
	_type			= 0;
	_isDigit		= 0;
	_isNotDigit		= 0;
	_isPoint		= 0;
	_isSpace		= 0;
	_isF			= 0;
	_sign			= 0;
	_isNeg			= 0;
	_int_overflow	= 0;
	_checkIf_F		= 'a';

	processInputString();
	storeCorrectType(); // ??? If this returns INVALID_INPUT, now still continues to convert()
						// Should it not then just exit here ??
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
	
	// PROBABLY NEED TO COPY ALL VARS HERE !!!

	this->_inputStr = src._inputStr;
	return *this;
}

// Destructor
Conversion::~Conversion()
{
	//std::cout << GRE"Destructor (Conversion) " << "\n" RES;
}


//////////////////////////////////////////////////////////
// Public member functions

// int	Conversion::convert_OLD()
// {
// 	//std::cout << "Convert: \n";
// 	if (_type == CHAR)
// 	{
// 		_intg	= (int)_c;
// 		_f		= (float)_c;
// 		_d		= (double)_c;
// 	}
// 	else if (_type == INT)
// 		_c = (int)_intg;
// 	else if (_type == FLOAT)
// 	{
// 		_c 		= (char)_f;
// 		_intg 	= (int)_f;
// 	}
// 	else if (_type == DOUBLE)
// 	{
// 		_c 		= (char)_d;
// 		_intg 	= (int)_d;
// 		_f 		= (double)_d;
// 	}
// 	else if (_type == NAN_OR_INF)
// 		return (0);
// 	return (0);
// }


int	Conversion::convert()
{
	//std::cout << "Convert: \n";
	if (_type == CHAR)
	{
		_intg	= static_cast<int>(_c);
		_f		= static_cast<float>(_c);
		_d		= static_cast<double>(_c);
	}
	else if (_type == INT)
		_c = static_cast<int>(_intg);
	else if (_type == FLOAT)
	{
		_c 		= static_cast<char>(_f);
		_intg 	= static_cast<int>(_f);
	}
	else if (_type == DOUBLE)
	{
		_c 		= static_cast<char>(_d);
		_intg 	= static_cast<int>(_d);
		_f 		= static_cast<double>(_d);
	}
	else if (_type == NAN_OR_INF)
		return (0);
	return (0);
}



void	Conversion::print_all()
{
	if (_type == CHAR && isprint(_c))
	{
		std::cout << "char:  '" << _c 		<< "'\n";
		std::cout << "int:    " << _intg	<<  "\n";
		std::cout << "float:  " << _f 		<<  ".0f\n";
		std::cout << "double: " << _d 		<<  ".0\n";
	}
	if (_type == INT || _type == FLOAT || _type == DOUBLE)
	{
		print_char();
		print_int();
		printFloatAndDouble();
	}
	if (_type == NAN_OR_INF)
		print_nan_or_inf();

	// ??????????????
	if (_type == INVALID_INPUT)	// this is not ok here, it should probably go to 
	{							// the convert section, and there check overflow for each type
		if (_int_overflow == 1)
		{
			std::cout << "char:  'not-possible'\n";
			std::cout << "int:   'not-possible'\n";
		}
	}
}



int	Conversion::storeCorrectType()
{
	//std::cout << "SCT: _type " << _type << " \n"; // HOW CAN _type HERE BE ZERO ??? IN CASE INPUT: "    "

	if (_type == INVALID_INPUT)
	{
		throw (ErrorException("Exception: INVALID INPUT, empty string"));
		return (INVALID_INPUT);
	}
	if (checkIntOverflow(&_inputStr[_start], INT_MAX) == 1)
		_int_overflow = 1;
	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit == 0)) // single sign found
		return (_type = CHAR);
	if ((_isNotDigit + _isPoint + _isF + _isDigit) == 1)	           // single char or a sign and 1 char
	{
		if (isSingleChar() != 0)
			return (_type);		
		else
		{
			std::cout << "Error: INVALID INPUT: _sign and alpha\n";
			throw (ErrorException("Exception: INVALID INPUT _sign and alphabet"));
		}
	}
	else if (_isPoint == 0 && _isNotDigit == 0 && _isF == 0)						// all digits, it's INT
		return (isInt());
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 0 && _isDigit >= 1)		// it's DOUBLE
		return (isDouble());
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 1 && _checkIf_F == 'f')	// it's FLOAT
	{
		//std::cout << BLU "SCT: is float: [" << _inputStr << "]\n" RES;
		return (isFloat());
	}
	else
		return (isNan_Inf_Invalid());									// it's nan, inf or invalid string
	return 0;
}


// Checks for invalid input, such as multiple . + - f . or multiple words, overflow, etc
int	Conversion::processInputString()
{
	// int ret = checkSpaces(_type, _inputStr, _c, _isNotDigit);
	int ret = checkSpaces();
	if (ret != 0)
	{
		//std::cout << "ret from CS: " << ret << "\n";
		return (ret);
	}
	checkDotOrSign(_inputStr, _i, _sign, _c, _isNeg);

	_start = _i;			// first char after . + - 
	checkString();
	while (_inputStr[_i]) 	// check the rest of space after 1st group of chars
	{
		if (isprint(_inputStr[_i]) && _inputStr[_i] != ' ')
		{
			//std::cout << _inputStr[_i] << " !!! Error, invalid input: found more chars after space!\n";
			throw(ErrorException("Exception: Invalid input: found more chars after space"));
			//return (1);
		}
		_i++;
	}
	return 0;
}
