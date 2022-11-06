/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/04 09:07:04 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Constructor
Data::Data() 
{
	std::cout << GRE"Default constr (Data) " << "\n" RES;
	_id = 0;
	_name = "Default_name";
}


// Param. constr.
Data::Data(int id, std::string name)
{
	std::cout << GRE"Param. constructor (Data), id: [" << _id << "], "
										"name: [" << _name << "],  \n" RES;
	_id = id;
	_name = name;
}



// Copy constructor
Data::Data(const Data &src)
{
	std::cout << GRE"Copy constructor:   " << "\n" RES;
	*this = src;
}



// Overload operators
Data& Data::operator= (const Data &src)
{
	std::cout << GRE"Overload operator=  (Data)" << "\n" RES;
	_id = src._id;
	_name = src._name;
	return *this;
}


// Destructor
Data::~Data()
{
	std::cout << GRE"Destructor (Data) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions
int Data::getId()
{
	std::cout << "ID: " << _id << "\n";
	return (_id);
}


std::string Data::getName()
{
	std::cout << "Name: " << _name << "\n";
	return (_name);
}
