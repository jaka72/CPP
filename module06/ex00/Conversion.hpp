/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/21 13:36:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <math.h>	// for isinf()
#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include "colors.h"

#ifdef __linux__
# include<bits/stdc++.h> //  for Linux
#endif
#ifdef __APPLE__
# include <limits>       // 
#endif


#define INVALID_INPUT 	-1
#define NAN_OR_INF		0
#define CHAR			1
#define INT				2
#define FLOAT			3
#define DOUBLE			4


class Conversion
{
	private:
		// input
		std::string _inputStr;

		// indexes
		int			_i;
		int			_start;

		// types
		char    	_c;
		int			_intg;
		float		_f;
		double		_d;
		int			_type;

		// markers
		int			_isDigit;
		int			_isNotDigit;
		int			_isPoint;
		int			_isSpace;
		int			_isF;
		int			_isNeg;
		int			_int_overflow;
		int			_sign;
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

		//Exceptions
		class ErrorException : public std::exception
		{
			public:
				ErrorException(const char* msg) throw();       
				virtual const char *what() const throw();
		};

		// Public member functions
		int		processInputString();
		int		storeCorrectType();
		int		convert();
		
		void	print_all();
		void	print_char();
		void	print_int();
		void	printFloatAndDouble();
		void	print_nan_or_inf();

		int		isSingleChar();
		int		isInt();
		int		isDouble();
		int		isFloat();
		int		isNan_Inf_Invalid();

		void	checkString();
		int		checkSpaces();
			
		// Getters
		// Setters
};

// Process Input String
void	checkDotOrSign(std::string &_inputStr, int &_i, int &_sign, char &_c, int &_isNeg);

// Check Int Overflow
int		checkIntOverflow(std::string str, int limit);
int		countDigits(int limit);

// Overload <<
// std::ostream& operator<< (std::ostream& outstream, Conversion &conv)
// {   }

#endif
