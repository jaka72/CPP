/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 11:12:47 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include "colors.h"

class Conversion
{
	private:
        std::string _inputStr;
		char    	_c;
		int			_intg;
		float		_f;
		double		_d;

		int			_i, _start, _isDigit, _isNotDigit, _isPoint, _isF;
		int			_sign;
		int			_isNeg;
		char		_checkIf_F;
		

	public:

		// Constructor
		Conversion();
		
		// Param. constr.
		Conversion(std::string str);

		// Copy constructor
		Conversion(const Conversion &src);

		// Destructor
		~Conversion();

		// Overload operators
		Conversion &operator= (const Conversion &src);


		// Public member functions
		int	processInputStr();
		int	storeCorrectType();


		// Getter



		// Setter


		// Exceptions


};

// THIS IS OUTSIDE OF THE CLASS !!!
// std::ostream& operator<< (std::ostream& outstream, Conversion &conv)
// {
// 	outstream << "Conversion " <<  bur.getInputStr() <<"\n";
// 	return (outstream);
// }

#endif

/////////////////////////////////////////////////////////////////////




// Constructor
Conversion::Conversion() 
{
	std::cout << GRE"Default constr (Conversion) " << "\n" RES;
}


// Param. constr.
Conversion::Conversion(std::string str) : _inputStr(str)
{
	std::cout << GRE"Param. constructor (Conversion) inputStr: [" << _inputStr << "]\n" RES;
	_i = 0;
	_c			= 'a';
    _intg		= 0 ;

	_isDigit = 0;
	_isNotDigit = 0;
	_isPoint = 0;
	_isF = 0;
	_sign = 0;
	_isNeg = 0;
	_checkIf_F = 'a';

	processInputStr();
	storeCorrectType();

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
int	Conversion::processInputStr()
{
	while (isspace(_inputStr[_i])) // skip spaces on start
	{
		//std::cout << "check space " << (int)_inputStr[_i] << "[" << _inputStr[_i] << "]\n";
		_i++;
	}
	
	//std::cout << "B) First after space " << _i << ",  " << (int)_inputStr[_i] <<"[" << _inputStr[_i] << "]\n";
	_c = _inputStr[_i];

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
			std::cout << _inputStr[_i] << " !!! Error, invalid input, found chars after space!\n";
			return 1;
			// break ;
		}
		_i++;
	}
	return 0;
}

/////////////////////////////////////////////////////



int checkNrDigits(int limit)
{
    int i = 0;
    std::cout << " first i=" << i << ",  limit " << limit << "\n";
    while (limit != 0)
    {
        limit = limit / 10;
        //std::cout << " ---- i=" << i << ",  limit " << limit << "\n";
        i++;
    }
    return (i);
}

// int max 2147483647
int check_overflow(std::string str, int limit)
{
    // count nr digits
    int lenStr = strlen(str.c_str());
    int lenLim = checkNrDigits(limit);

    std::cout << "check overflow\n";
    std::cout << "      lenStr " << lenStr << "\n";
    std::cout << "      lenLim " << lenLim << "\n";

    if (lenStr > lenLim)
    {
        std::cout << "      OVERFLOW INT [" << str << "]\n";
        return (1);
    }
    else if (lenStr == lenLim)
    {
        // Compare all digits except the last one, then compare the last one separately
        std::string firstSubStr = str.substr(0, lenStr - 1);
        std::string  lastSubStr = str.substr(lenStr - 1, lenStr);
        std::cout << "      same lenght, firstSubstr [" << firstSubStr << "]\n";
        std::cout << "      same lenght, lastSubstr  [" <<  lastSubStr << "]\n";
            
        if (atoi(firstSubStr.c_str()) > abs(limit / 10))
        {
            std::cout << "      same lenght, FirstSubstr, OVERFLOW [" << str << "]\n";
            return (1);
        }
        else if (atoi(firstSubStr.c_str()) == abs(limit / 10))
        {
            if (atoi(lastSubStr.c_str()) > abs(limit % 10))
            {    
                std::cout << "      same lenght, LastSubstr, OVERFLOW [" << str << "]\n";
                return (1);
            }
        }
    }
    return (0);
}


void printStats(int isDigit, int isNotDigit, int isPoint, int isF, int sign, int isNeg)
{
    std::cout << "      digits:     " << isDigit << "\n";
    std::cout << "      non-digits: " << isNotDigit << "\n";
    std::cout << "      points:     " << isPoint << "\n";
    std::cout << "      fs:         " << isF << "\n";
    std::cout << "      sign:       " << sign << "\n";
    std::cout << "      isNeg:      " << isNeg << "\n";
}


int	Conversion::storeCorrectType()
{
	//std::cout << "   all together: " << isNotDigit + isPoint + isF + isDigit << "\n";

	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit == 0))
	{
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg);
		std::cout << "SINGLE CHAR THE SIGN FOUND\n";
		std::cout << "Must be CHAR, str [" << _inputStr << "],  c [" << _c << "]\n"; 
		std::cout << "Result: " << _c << "\n";
		return (11);
	}
	
	
	if (_sign == 0 && (_isNotDigit + _isPoint + _isF + _isDigit) == 1)
	{
		std::cout << "SINGLE CHAR \n";
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg);

		if (_isNotDigit == 1)
		{
			std::cout << "Must be CHAR, str [" << _inputStr << "],  c [" << _c << "]\n"; 
			std::cout << "Result: " << _c << "\n";
			return (11);
		}
		if (_isDigit == 1)
		{
			std::cout << "Must be SINGLE INT, str [" << _inputStr << "],  c [" << _i << "]\n";
			_i = (int)(_inputStr[_start] - 48);
			std::cout << "Result: " << _i << "\n";
			return (11);
		}
	}
	if (_sign == 1 && (_isNotDigit + _isPoint + _isF + _isDigit) == 1)
	{
		if (_isDigit == 1)
		{
			std::cout << "Must be SINGLE INT WITH SIGN, str [" << _inputStr << "],  c [" << _inputStr[_start] << "]\n";
			_i = (int)(_inputStr[_start] - 48);
			if (_isNeg == 1)
				_i *= -1;
		
			std::cout << "Result: " << _i << "\n";
			return (11);
		}
		else
		{
			std::cout << "INVALID INPUT: _sign and alpha" << _i << "\n";
		}
			
	}
	// check if all good
	else if (_isPoint == 0 && _isNotDigit == 0 && _isF == 0)
	{
		std::cout << "Must be integer: " << _inputStr << "\n";
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg);

		// choose the correct limit
		int limit;
		if (_isNeg == 0)
			limit = std::numeric_limits<int>::max();
		else
			limit = std::numeric_limits<int>::min();

		
		// if (check_overflow(&str[start], std::numeric_limits<int>::max() ) != 0)
		if (check_overflow(&_inputStr[_start], limit) != 0)
		{
			std::cout << "Int overflow!\n";
			return (1);
		}
		
		_intg = atoi(&_inputStr[_start]);
		if (_isNeg == 1)
			_intg *= -1;
		
		std::cout << "Result: " << _intg << "\n";
		std::cout << "        integer: " << _intg << " limit: " << limit << "\n";
	
	return (22);
	}

	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 0 && _isDigit >= 1)
	{
		printStats(_isDigit, _isNotDigit, _isPoint, _isF, _sign, _isNeg);
		std::cout << "Must be double: " << _inputStr << "\n";
		_d = atof(&_inputStr[_start]); // ??????
		if (_isNeg == 1)
			_d *= -1;
		std::cout << "Result: " << _d << "\n";
		return (33);
	}
	else if (_isPoint == 1 && _isNotDigit == 0 && _isF == 1 && _checkIf_F == 'f')
	{
		std::cout << "Must be float: " << _inputStr << "\n";
		_f = atof(&_inputStr[_start]);
		if (_isNeg == 1)
			_f *= -1;
		std::cout << "Result: " << _f << "\n";
		return (44);
	}
	else   
	{
		std::cout << "Error: last char is not f and not digit!\n";
		return (1);
	}    

    return 0;
}











