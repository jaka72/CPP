/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_storeType.cpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:39:44 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/23 12:48:51 by jmurovec      ########   odam.nl         */
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



int	Conversion::isInt()
{
	_intg = atoi(&_inputStr[_start]);
	if (_int_overflow == 0)
	{
		_f = static_cast<float>(_intg);
		_d = static_cast<double>(_intg);
	}
	else
	{
		_f = atof(&_inputStr[_start]);	// In case of overflow, it must 
		_d = atof(&_inputStr[_start]);	// preserve the orig value for the float
	}
	if (_isNeg == 1)
	{
		_intg *= -1;
		if (_intg != -2147483648)	// Anomaly: because above the _intg is saved as absolute, always positive
		{							// 	and this value is already over INT_MAX
			_f *= -1;
			_d *= -1;
		}
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
	_d = atof(&_inputStr[_start]);
	_intg = static_cast<int>(_d);
	_f = static_cast<float>(_d);

	if (_isNeg == 1)
	{
		_intg *= -1;
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
