/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 14:59:09 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <math.h>	// for isinf()
#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>   // overflow CPP
// #include <bits/stdc++.h> // overflow C   Linux
#include "colors.h"

#define INVALID_INPUT 	-1
#define NAN_OR_INF		0
#define CHAR			1
#define INT				2
#define FLOAT			3
#define DOUBLE			4


// typedef struct s_indexes t_indx;

// struct s_indexes
// {
// 	size_t	_i;
// 	size_t	_start;
// };


class Conversion
{
	private:
	
        std::string _inputStr;

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

		// indexes
		int			_i;
		int			_start; // change to size_t

		// t_indx	indx;

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


		void	checkString();
		int		checkSpaces();
		// int		checkSpaces(int _type, std::string &_inputStr, char &_c, int &_isNotDigit);



};

// THE OVERLOAD<< MUST BE OUTSIDE OF THE CLASS. MAYBE NEEDS TO BE UNCOMMENTED, AS PART OF THE SUBJECT
// std::ostream& operator<< (std::ostream& outstream, Conversion &conv)
// {
// 	outstream << "Conversion " <<  bur.getInputStr() <<"\n";
// 	return (outstream);
// }



// To process Input String
// int		checkSpaces(int _type, std::string &_inputStr, char &_c, int &_isNotDigit);
void	checkDotOrSign(std::string &_inputStr, int &_i, int &_sign, char &_c, int &_isNeg);

// To check Int Overflow
int		checkIntOverflow(std::string str, int limit);
int		countDigits(int limit);


// void	checkStringOLD(std::string &_inputStr, int &_i, int &_isDigit, int &_isNotDigit,
// 							int &_isPoint, int &_isF, char &_checkIf_F, char &_c);

#endif
