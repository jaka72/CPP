/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/03 22:16:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructor
Data::Data() 
{
	std::cout << GRE"Default constr (Data) " << "\n" RES;
}


// Param. constr.
// Data::Data(std::string str)
// {
// 	std::cout << GRE"Param. constructor (Data) inputStr: [" << "]\n" RES;

// }



// Copy constructor
// Data::Data(const Data &src)
// {
// 	std::cout << GRE"Copy constructor:   " << "\n" RES;
// 	*this = src;
// }



// Overload operators
// Data& Data::operator= (const Data &src)
// {
// 	std::cout << GRE"Overload operator=  (Data)" << "\n" RES;

// 	return *this;
// }

// Destructor
Data::~Data()
{
	std::cout << GRE"Destructor (Data) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions


