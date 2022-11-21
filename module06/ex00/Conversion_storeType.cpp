/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_storeType.cpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:39:44 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/21 15:59:55 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"


int	Conversion::isSingleChar()
{
	if ((_isNotDigit == 1 || _isPoint == 1 || _isSpace == 1) && _sign != 1)
		return (_type = CHAR);

	if (_isDigit == 1)
	{
		_intg = static_cast<int>(_inputStr[_start] - 48);
		if (_isNeg == 1)
			_intg *= -1;
											
		_f = static_cast<float>(_intg);
		_d = static_cast<double>(_intg);
		return (_type = INT);				
	}
	return (0);
}


// MOVED CASTING FROM convert() TO HERE,
// IN CASE OF OVERFLOW, FLOAT MUST PRESERVE VALUE FROM ORIGINAL INPUT
int	Conversion::isInt()
{
//	long double temp = atof(&_inputStr[_start]);	// check_overflow via long double
//	if (temp > INT_MAX || temp < INT_MIN)
//		_int_overflow = 1;;
	_intg = atoi(&_inputStr[_start]);
	if (_int_overflow == 0)
	{
		_f = static_cast<float>(_intg);
		_d = static_cast<double>(_intg);
	}
	else
	{
		_f = atof(&_inputStr[_start]);	// IN CASE OF OVERFLOW IT MUST 
		_d = atof(&_inputStr[_start]);	// PRESERVE THE ORIG VALUE FOR THE FLOAT
	}
	if (_isNeg == 1)
	{
		_intg *= -1;
		_f *= -1;
		_d *= -1;
	}
	return (_type = INT);
}


int Conversion::isDouble()
{
	_d = atof(&_inputStr[_start]);
	if (_isNeg == 1)
		_d *= -1;
	return (_type = DOUBLE);		
}


int	Conversion::isFloat()
{
	_f = atof(&_inputStr[_start]);
	_d = atof(&_inputStr[_start]);
	if (_isNeg == 1)
	{
		_f *= -1;
		_d *= -1;
	}
	return (_type = FLOAT);
}


int	Conversion::isNan_Inf_Invalid()
{
	if (_inputStr == "nan" || _inputStr == "nanf")
		return (_type = NAN_OR_INF);

	else if (_sign == 1 && (_inputStr == "+inf" || _inputStr == "+inff"
						||	_inputStr == "-inf" || _inputStr == "-inff"))
		return (_type = NAN_OR_INF);
	else
		throw (ErrorException("Exception: Invalid input!"));
	return (1);
}
