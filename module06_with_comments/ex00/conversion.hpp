/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/02 20:08:40 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>       // overflow CPP
#include<bits/stdc++.h> // overflow C   PROBABLY BETTER USE THE CPP LIMITS
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

		int			_i, _start, _isDigit, _isNotDigit, _isPoint, _isSpace, _isF;
		int			_int_overflow, _float_overflow, _double_overflow;
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
		int		processInputStr();
		int		storeCorrectType();
		int		convert();
		void	print_all();
		void	print_char();





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









