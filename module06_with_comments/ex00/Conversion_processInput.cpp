/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_processInput.cpp                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:43:17 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/07 14:45:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// IT NEEDS TO DETECT A SINGLE SPACE AND SINGLE DOT !!!
std::string trimWhiteSpaces(std::string str)
{
	const char* whiteSpaces = " \n\r\t\f\v";
	
	str.erase(0, str.find_first_not_of(whiteSpaces));	// at start
	str.erase(str.find_last_not_of(whiteSpaces) + 1);	// at end
	return str;
}


int	checkSpaces(int _type, std::string &_inputStr, char &_c, int &_isNotDigit)
{
	if (strlen(_inputStr.c_str()) == 1 && _inputStr[0] == ' ')
	{									// Check immediately for ' ' single space
		_c = _inputStr[0];
		_isNotDigit++;
		return (_type = CHAR);
	}
	if (strlen(_inputStr.c_str()) > 1)	// multiple spaces
	{
		size_t i = 0;
		while (_inputStr[i])
		{
			if (!isspace(_inputStr[i]))
				break ;
			i++;
		}
		if (i == strlen(_inputStr.c_str()))	// only empty spaces in string
		{
			return (_type = INVALID_INPUT);
		}
	}
	_inputStr = trimWhiteSpaces(_inputStr);
	return (0);
}


void	checkDotOrSign(std::string &_inputStr, int &_i, int &_sign, char &_c, int &_isNeg)
{
	if (_inputStr[_i] == '.')	// check 1st char after spaces
		_c = '.';
		
	if (_inputStr[_i] == '+' || _inputStr[_i] == '-')
	{
		_sign = 1;
		_c = _inputStr[_i];
		if (_inputStr[_i] == '-')
			_isNeg = 1;
		_i++;
		while (isspace(_inputStr[_i])) // skip spaces after sign
		{
			_i++;
		}
	}
}

// Checking if multiple . or f in the input string
void checkString(std::string &_inputStr, int &_i, int &_isDigit, int &_isNotDigit,
						 int &_isPoint, int &_isF, char &_checkIf_F, char &_c)
{
	while (_inputStr[_i])
	{
		if (!isdigit(_inputStr[_i]) && _inputStr[_i] != '.' && _inputStr[_i] != 'f' && _inputStr[_i] != ' ')
		{
			_isNotDigit++;
			_c = _inputStr[_i];
		}
		if (isdigit(_inputStr[_i]))
			_isDigit++;
		if (_inputStr[_i] == '.')
			_isPoint++;
		if (_inputStr[_i] == 'f')
		{
			_isF++;
			if (_inputStr[_i + 1] == '\0' || _inputStr[_i + 1] == ' ') // found space or \0
			{
				_checkIf_F = _inputStr[_i];
			}    
		}
		if (_inputStr[_i] == ' ')	// found space before end
		{
			_checkIf_F = _inputStr[_i - 1];
			break ;
		}
		_i++;
	}
}
