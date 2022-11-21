/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_printAll.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:54:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/21 12:51:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"


void	Conversion::print_char()
{
	if ((_intg >= 0 && _intg <= 31) || (_intg >= 127 && _intg <= 255))
		std::cout << "char:  'non-printable'\n";
	else if (_intg < 0 || _intg > 255)
		std::cout << "char:  'not-possible'\n";
	else
		std::cout << "char:  '" << _c 		<< "'\n";
}


// HERE IS A PROBLEM, BECAUSE THE FLOAT IS BY NOW IN SCIENTIFIC NOTATION, WHICH IS
// ROUNDED DOWN, SO _f IS SMALLER THAN max(), INSTEAD OF SAME OR BIGGER.
// (AT MORE THAN 6 DIGITS, THE FLOAT CHANGES INTO SCIENTIFIC NOTATION)
// I NEED TO CHECK FOR INT OVERFLOW ALREADY AT START, BEFORE SAVING IT INTO FLOAT
void	Conversion::print_int()
{
	if (_int_overflow == 1)
		std::cout << "int:    not-possible\n";
	else
		std::cout << "int:    " << _intg <<  "\n";
}


void	Conversion::print_nan_or_inf()
{
	if (_inputStr == "nanf")
		_inputStr = "nan";
	else if (_inputStr == "-inff")
		_inputStr = "-inf";
	else if (_inputStr == "+inff")
		_inputStr = "+inf";
	if (_inputStr == "+inf" || _inputStr == "-inf" || _inputStr == "nan")
	{
		std::cout << "char: not-possible\n";
		std::cout << "int: not-possible\n";
		std::cout << "float:  " << _inputStr << "f\n";
		std::cout << "double: " << _inputStr << "\n";
	}
}


void	Conversion::printFloatAndDouble()
{
	if (_type == INT || _type == FLOAT || _type == DOUBLE)
	{
		if (_f - (int)_f == 0 && _f < 10000)	//std::cout << "FLOAT, no decimals\n";
		{
			std::cout << "float:  " << _f 		<<  ".0f\n";
			std::cout << "double: " << _d 		<<  ".0\n";
		}
		else
		{
			std::cout << "float:  " << _f 		<<  "f\n";
			std::cout << "double: " << _d 		<<  "\n";
		}
	}
}
