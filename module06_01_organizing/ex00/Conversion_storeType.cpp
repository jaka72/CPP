/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_storeType.cpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:39:44 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 22:04:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"


int	Conversion::isSingleChar()
{
	if ((_isNotDigit == 1 || _isPoint == 1 || _isSpace == 1) && _sign != 1)
	{
		return (_type = CHAR);
	}
	if (_isDigit == 1)
	{
		_intg = static_cast<int>(_inputStr[_start] - 48);
		if (_isNeg == 1)
			_intg *= -1;
											// MOVED CASTING FROM convert() TO HERE,
		_f = static_cast<float>(_intg);		// BECAUSE OF OVERFLOW - OTHERWISE IT NEVER STORES
		_d = static_cast<double>(_intg);	// TO FLOAT, IN CASE OF OVERFLOW IT MUST 
		return (_type = INT);				// HAVE VALUE FROM ORIGINAL INPUT
	}
	return (0);
}



int	Conversion::isInt()
{
	// int n;
    // std::string s1 = "1234";
	// n = stoi(s1);			// stoi not recognized here, but works in _test_stoi ???????
    //     std::cout << n << "\n";


	
	long double temp = atof(&_inputStr[_start]);	// check_overflow via long double
	if (temp > INT_MAX || temp < INT_MIN)			// int overflow
		_int_overflow = 1;;
	

	// stoi NOT WORKING WITH POINTER AND INDEX
	// NEEDS TO BE FIRST STORED INTO STRING
	// BUT THEN ON LINUX, IT NEEDS A TRICK, 
	// TEMPORARY DISABLE ALL FLAGS IN MAKEFILE and then put it back ???
	std::string str;
	str.assign(&_inputStr[_start]);
	_intg = stoi(str);  // issue in linux, not recognized stof ???

	//_intg = atoi(&_inputStr[_start]);  // issue in linux, not recognized stof ???
	_f    = atof(&_inputStr[_start]);	// IN CASE OF OVERFLOW IT MUST 
	_d    = atof(&_inputStr[_start]);	// RETAIN THE ORIG VALUE FOR THE FLOAT

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
	_d = atof(&_inputStr[_start]); // ??????
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
		std::cout << "Error: Invalid input, last char is not f and not digit!\n";
	return (1); // maybe here should return type == 0 or something
}
