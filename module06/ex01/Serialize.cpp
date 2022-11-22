/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/22 16:19:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

// Constructor
Serialize::Serialize() 
{
	std::cout << GRE"Default constr (Serialize) " << "\n" RES;
}


// Param. constr.
Serialize::Serialize(int, std::string)
{
	// std::cout << GRE"Param. constructor (Serialize), id: [" << _id << "], "
	// 									"name: [" << _name << "],  \n" RES;
}



// Copy constructor
Serialize::Serialize(const Serialize &src)
{
	std::cout << GRE"Copy constructor:   " << "\n" RES;
	*this = src;
}



// Overload operators
Serialize& Serialize::operator= (const Serialize &)
{
	std::cout << GRE"Overload operator=  (Serialize)" << "\n" RES;
	return *this;
}


// Destructor
Serialize::~Serialize()
{
	std::cout << GRE"Destructor (Serialize) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions


uintptr_t	Serialize::serialize(Data* ptr)
{
	uintptr_t	i;
	i = reinterpret_cast<uintptr_t>(ptr);
	
	std::cout << MAG"   Called serialize(): " RES;
	std::cout << MAG"   The Pointer is now stored into uintptr_t\n" RES;
	
	return (i);
}


Data*		Serialize::deserialize(uintptr_t raw)
{
	std::cout << MAG"   Called deserialize(): " RES;
	std::cout << MAG" The uintptr_t is now returned to a pointer\n" RES;
	
	return (reinterpret_cast<Data*>(raw));
}
