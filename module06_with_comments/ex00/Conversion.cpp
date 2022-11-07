/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/07 15:10:06 by jaka          ########   odam.nl         */
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
	//std::cout << GRE "Param. constructor (Conversion)" RES << "\n";
	// std::cout << GRE "inputStr: [" << _inputStr << "]\n" RES;
	_i          	= 0;
	_c				= 'x';
	_intg			= 0 ;

	_type			= 0;
	_isDigit		= 0;
	_isNotDigit		= 0;
	_isPoint		= 0;
	_isSpace		= 0;
	_isF			= 0;
	_sign			= 0;
	_isNeg			= 0;
	_checkIf_F		= 'a';
	_int_overflow	= 0;

	processInputString();
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
	//std::cout << GRE"Destructor (Conversion) " << "\n" RES;
}


//////////////////////////////////////////////////////////
// Public member functions

int	Conversion::convert()
{
	if (_type == CHAR)
	{
		_intg	= (int)_c;
		_f		= (float)_c;
		_d		= (double)_c;
	}
	else if (_type == INT)
		_c = (int)_intg;
	else if (_type == FLOAT)
	{
		_c 		= (char)_f;
		_intg 	= (int)_f;
		if (isinf(_f))		// SOMETHING NOT GOOD, SHOULD BE inf == true ???
			_d 	= (double)_f;
	}
	else if (_type == DOUBLE)
	{
		_c 		= (char)_d;
		_intg 	= (int)_d;
		_f 		= (double)_d;
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


int	Conversion::processInputString()
{
	int ret = checkSpaces(_type, _inputStr, _c, _isNotDigit);
	if (ret != 0)
		return (ret);
	
	checkDotOrSign(_inputStr, _i, _sign, _c, _isNeg);

	_start = _i;			// first char after . + - 
	checkString(_inputStr, _i, _isDigit, _isNotDigit, _isPoint, _isF, _checkIf_F, _c);
	
	while (_inputStr[_i]) 	// check the rest of space after 1st group of chars
	{
		if (isprint(_inputStr[_i]) && _inputStr[_i] != ' ')
		{
			std::cout << _inputStr[_i] << " !!! Error, invalid input: found more chars after space!\n";
			return 1;
		}
		_i++;
	}
	return 0;
}


int	Conversion::storeCorrectType()
{
	if (checkIntOverflow(&_inputStr[_start], INT_MAX) == 1)
		_int_overflow = 1;
	if (_type == INVALID_INPUT)
		return (INVALID_INPUT);
	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit == 0)) // single sign found
		return (_type = CHAR);
	if ((_isNotDigit + _isPoint + _isF + _isDigit) == 1)	           // single char or a sign and 1 char
	{
		if (isSingleChar() != 0)
			return (_type);		
		else
			std::cout << "Error: INVALID INPUT: _sign and alpha\n";
	}
	else if (_isPoint == 0 && _isNotDigit == 0 && _isF == 0)						// all digits, it's INT
		return (isInt());
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 0 && _isDigit >= 1)		// it's DOUBLE
		return (isDouble());
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 1 && _checkIf_F == 'f')	// it's FLOAT
		return (isFloat());
	else
		return (isNan_Inf_Invalid());									// it's nan, inf or invalid string
	return 0;
}
