/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/01 18:11:00 by jaka          ########   odam.nl         */
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









