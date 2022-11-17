/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 17:46:15 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <math.h>	// for isinf()
#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>       // overflow CPP
// #include <bits/stdc++.h> // overflow C   Linux
#include "colors.h"

#define INVALID_INPUT -1
#define NAN_OR_INF	0
#define CHAR		1
#define INT			2
#define FLOAT		3
#define DOUBLE		4


class Conversion
{
	private:
	
        std::string _inputStr;
		char    	_c;
		int			_intg;
		float		_f;
		double		_d;
		int			_type;

		int			_i, _start;
		int			_isDigit, _isNotDigit;
		int			_isPoint, _isSpace, _isF;
		int			_int_overflow;
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
		int		processInputString();
		int		storeCorrectType();
		
		int		isSingleChar();
		int		isInt();
		int		isDouble();
		int		isFloat();
		int		isNan_Inf_Invalid();

		int		convert();
	
		void	print_all();
		void	print_char();
		void	print_int();
		void	printFloatAndDouble();
		void	print_nan_or_inf();
		
		// Getter

		// Setter

		// Exceptions
};

// THE OVERLOAD<< MUST BE OUTSIDE OF THE CLASS. MAYBE NEEDS TO BE UNCOMMENTED, AS PART OF THE SUBJECT
// std::ostream& operator<< (std::ostream& outstream, Conversion &conv)
// {
// 	outstream << "Conversion " <<  bur.getInputStr() <<"\n";
// 	return (outstream);
// }



// To process Input String
int		checkSpaces(int _type, std::string &_inputStr, char &_c, int &_isNotDigit);
void	checkDotOrSign(std::string &_inputStr, int &_i, int &_sign, char &_c, int &_isNeg);
void	checkString(std::string &_inputStr, int &_i, int &_isDigit, int &_isNotDigit,
							int &_isPoint, int &_isF, char &_checkIf_F, char &_c);


// To check Int Overflow
int		checkIntOverflow(std::string str, int limit);
int		countDigits(int limit);

#endif
